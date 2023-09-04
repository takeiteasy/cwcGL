=begin
gl.rb -- https://github.com/takeiteasy/fungl

The MIT License (MIT)

Copyright (c) 2022 George Watson

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge,
publish, distribute, sublicense, and/or sell copies of the Software,
and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
=end

require "nokogiri"
require "net/http"

# Download required files if needed
xml = ["https://registry.khronos.org/EGL/api/KHR/khrplatform.h",
       "https://raw.githubusercontent.com/KhronosGroup/OpenGL-Registry/main/xml/gl.xml"]
xml.each do |x|
    xp = "tools/" + File.basename(x)
    next if File.exist? xp
    resp = Net::HTTP.get_response URI(x)
    abort "ERROR: #{resp.code}" unless resp.is_a? Net::HTTPSuccess
    File.write xp, resp.body
end

# Parse gl.xml with Nokogiri
doc = Nokogiri::XML File.open("tools/gl.xml") do |config|
  config.options = Nokogiri::XML::ParseOptions::STRICT | Nokogiri::XML::ParseOptions::NOBLANKS
end

# Parse <types>
types = doc.xpath("//types").children.reject { |c| c.class.to_s == "Nokogiri::XML::Comment" }.map do |t|
    html = t.inner_html.gsub "<apientry></apientry>", "APIENTRY"
    /<name>(?<name>.*)<\/name>/ =~ html
    [name, t.text]
end.to_h.delete_if { |k, v| k.nil? }
# Parse <enums>
enums = doc.xpath("//enums").children.map { |e| [e.attr('name'), e.attr('value')] }.to_h
# Parse <commands>
commands = doc.xpath("//commands").children.map do |f|
    parts = {:params => []}
    name = nil
    f.children.each do |ff|
        case ff.to_s
        when /^<proto/
            fff = ff.children.to_a
            name = fff.pop.text
            parts[:result] = fff.map { |ffff| ffff.text.strip }.join " "
        when /^<param/
            parts[:params] << ff.children.to_a.map { |ffff| ffff.text.strip }.join(" ")
        end
    end
    parts[:params] = ["void"] if parts[:params].empty?
    [name, parts]
end.to_h

puts <<HEADER
#define __gl_glcorearb_h_ 1  /* Khronos core */
#define __gl_glext_h_ 1      /* Khronos compatibility */
#define __gl_h_ 1            /* Windows/Linux */
#define __GL_H__ 1           /* Windows */
#define __gl3_h_ 1           /* Mac */

#if defined(_WIN32) && !defined(APIENTRY) && !defined(__CYGWIN__) && !defined(__SCITECH_SNAP__)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif
#include <windows.h>
#define APIENTRY __stdcall
#endif

#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
#endif
#ifndef GLAPI
#if defined(GLAD_GLAPI_EXPORT)
#if defined(_WIN32) || defined(__CYGWIN__)
#if defined(GLAD_GLAPI_EXPORT_BUILD)
#if defined(__GNUC__)
#define GLAPI __attribute__ ((dllexport)) extern
#else
#define GLAPI __declspec(dllexport) extern
#endif
#else
#if defined(__GNUC__)
#define GLAPI __attribute__ ((dllimport)) extern
#else
#define GLAPI __declspec(dllimport) extern
#endif
#endif
#elif defined(__GNUC__) && defined(GLAD_GLAPI_EXPORT_BUILD)
#define GLAPI __attribute__ ((visibility ("default"))) extern
#else
#define GLAPI extern
#endif
#else
#define GLAPI extern
#endif
#endif

#if !defined(EZGL_VERSION)
#define EZGL_VERSION 1000
#endif
HEADER

# Find <feature>, remove any unused gl versions
features = doc.xpath("//feature").select { |f| f.attr('name') =~ /^GL_VERSION_\d_\d$/ }

# Print out version macros
features.each do |f|
    maj, min = f.attr('number').split('.')
    puts "#define #{f.attr 'name'} #{maj}0#{min}0"
end

# Parse and print khrplatform.h
khr = File.readlines("tools/khrplatform.h").map { |l| l.rstrip }[4..-2]
puts "\n/* khrplatform.h -- [https://registry.khronos.org/EGL/api/KHR/khrplatform.h]", khr.join("\n"), "/* end of khrplatform.h */", ""

# Format features for each gl version
defined = []
functions = {}
features.each do |f|
    puts "#if EZGL_VERSION >= #{f.attr 'name'}"
    ver = f.attr 'number'
    functions[ver] = []
    
    f.children.each do |ff|
        ff.children.each do |fff|
            name = fff.attr("name")
            if fff.to_s =~ /^<command/
                commands[name][:params].each do |p|
                    t = p.split(" ").select! { |pp| pp =~ /GL/ }
                    unless t.nil?
                        t.each do |tt|
                            unless defined.include? tt
                                puts types[tt]
                                defined << tt
                            end
                        end
                    end
                end
            end
        end
    end
    
    f.children.each do |ff|
        ff.children.each do |fff|
            name = fff.attr("name")
            next if defined.include? name
            case fff.to_s
            when /^<type/
                puts types[name]
            when /^<enum/
                puts "#define #{name} #{enums[name]}"
            when /^<command/
                proc = "PFN#{name.upcase}PROC"
                puts "typedef #{commands[name][:result]} (APIENTRYP #{proc})(#{commands[name][:params].join ', '});"
                puts "#define #{name} gll_#{name}"
                functions[ver].append [proc, name]
            end
            defined << name
        end
    end
    puts "#endif"
    puts
end

# Store functions in macros for later
functions.each do |k, v|
    puts "", "#define GL_FUNCTIONS_#{k.gsub '.', '_'} \\"
    v.each do |vv|
        puts "\tX(#{vv[0]}, #{vv[1]}) \\"
    end
end

# Define functions externs
puts "", "#define X(T, N) extern T gll_##N;"
functions.each do |k, v|
    maj, min = k.split '.'
    puts "#if EZGL_VERSION >= GL_VERSION_#{maj}_#{min}"
    puts "GL_FUNCTIONS_#{maj}_#{min}"
    puts "#endif"
end
puts "#undef X", ""
