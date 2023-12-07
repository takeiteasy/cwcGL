=begin
gl.rb -- https://github.com/takeiteasy/cwcGL

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

$DisableFileOut = false
$EnableHeaderFileOut = !$DisableFileOut
$EnableSourceFileOut = !$DisableFileOut
$DisableWrapperOut = false
$DisableGLLoaderOut = false
$OutputGLBindings = false

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
$GLhandleARB=nil
types = doc.xpath("//types").children.reject { |c| c.class.to_s == "Nokogiri::XML::Comment" }.map do |t|
  html = t.inner_html.gsub "<apientry></apientry>", "APIENTRY"
  /<name>(?<name>.*)<\/name>/ =~ html
  unless name
    $GLhandleARB = t.text unless t.text.start_with?("#include")
  end
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

# INFO: Start of writing header

$OriginalOut = $>.clone

def RestoreOriginalOut
  $>.close
  $> = $OriginalOut
end

$> = File.open("src/glWrapper.h", 'w') if $EnableHeaderFileOut

puts <<HEADER
/*

 This file was generated by https://github.com/takeiteasy/cwcGL/blob/master/tools/gl.rb

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
*/

#ifndef CWCGL_WRAPPER_HEADER
#define CWCGL_WRAPPER_HEADER
#ifdef __cplusplus
extern "C" {
#endif

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

#if !defined(EXPORT)
#if defined(CWCGL_WINDOWS)
#define EXPORT __declspec(dllexport)
#elif defined(CWCGL_EMSCRIPTEN)
#define EXPORT EMSCRIPTEN_KEEPALIVE
#else
#define EXPORT
#endif
#endif

#if !defined(CWCGL_VERSION)
#define CWCGL_VERSION 1000
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

# Format features for each OpenGL version
defined = []
$functions = {}
features.each do |f|
  ver = f.attr 'number'
  $functions[ver] = []
  output = []

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
                types.delete(tt)
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
        output.append(types[name])
      when /^<enum/
        puts "#define #{name} #{enums[name]}"
      when /^<command/
        proc = "PFN#{name.upcase}PROC"
        $functions[ver].append [proc, name]
      end
      defined << name
    end
  end

  unless output.empty?
    puts "#if CWCGL_VERSION >= #{f.attr 'name'}"
    puts output.join("\n")
    puts "#endif"
  end
end

puts "", "typedef khronos_intptr_t GLintptr;"
types.each do |k, v|
  if v.start_with?("typedef")
    puts v unless v.start_with?("typedef void (")
  end
end
puts $GLhandleARB, "" if $GLhandleARB

# Store functions in macros for later
def PrintGLVersionsMacro
  $functions.each do |k, v|
    puts "", "#define GL_FUNCTIONS_#{k.gsub '.', '_'} \\"
    v.each do |vv|
      puts "\tX(#{vv[0]}, #{vv[1]}) \\"
    end
  end
  puts
end

# Define extern functions
if $OutputGLBindings
  PrintGLVersionsMacro()
  puts "#define X(T, N) extern T __##N;"
  $functions.each do |k, v|
    maj, min = k.split '.'
    puts "#if CWCGL_VERSION >= GL_VERSION_#{maj}_#{min}"
    puts "GL_FUNCTIONS_#{maj}_#{min}"
    puts "#endif"
  end
  puts "#undef X", ""
end

# Define command-types enum for each OpenGL function
puts "typedef enum {"
commands.each do |k, _|
  puts "    cwc#{k}Command,"
end
puts "} GLcommandType;"

puts <<STRUCTS

typedef struct GLcommand {
    GLcommandType type;
    void *data;
    struct GLcommand *next, *prev;
} GLcommand;

typedef struct {
    GLcommand *front, *back;
} GLcontext;

STRUCTS

# Generate header definitions
if not $DisableWrapperOut
  $functions.each do |k, v|
    maj, min = k.split '.'
    puts "#if CWCGL_VERSION >= GL_VERSION_#{maj}_#{min}"
    v.each do |vv|
      cmd = commands[vv[1]]
      argsVoid = (cmd[:params].length == 1 and cmd[:params][0] == "void")
      returnsVoid = cmd[:result] == "void"
      params = cmd[:params].join ", "
      returnValue = returnsVoid ? "" : ", #{cmd[:result]}* return_value"
      puts "EXPORT void cwc#{vv[1]}(GLcontext *context#{params == "void" ? "" : ", " + params}#{returnValue});"
    end
    puts "#endif"
  end
end

puts "EXPORT int InitOpenGL(void);" if not $DisableGLLoaderOut

puts <<FOOTER

#ifdef __cplusplus
}
#endif
#endif // CWCGL_WRAPPER_HEADER
FOOTER

RestoreOriginalOut() if $EnableHeaderFileOut

# INFO: Start of writing source

$> = File.open("src/glWrapper.c", "w") if $EnableHeaderFileOut

puts <<SOURCE
/*

 This file was generated by https://github.com/takeiteasy/cwcGL/blob/master/tools/gl.rb

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
*/

#include "glWrapper.h"
#include <stdlib.h>

SOURCE

PrintGLVersionsMacro() if not $OutputGLBindings

# Define OpenGL functions
features.each do |f|
  puts "#if CWCGL_VERSION >= #{f.attr 'name'}"
  f.children.each do |ff|
    ff.children.each do |fff|
      name = fff.attr("name")
      next unless defined.include? name
      if fff.to_s =~ /^<command/
        proc = "PFN#{name.upcase}PROC"
        puts "typedef #{commands[name][:result]} (APIENTRYP #{proc})(#{commands[name][:params].join ', '});"
        puts "#define #{name} __#{name}"
      end
      defined << name
    end
  end
  puts "#endif", ""
end

# Define extern implementations
puts "#define X(T, N) T __##N = (T)((void*)0);"
$functions.each do |k, v|
  maj, min = k.split '.'
  puts "#if CWCGL_VERSION >= GL_VERSION_#{maj}_#{min}"
  puts "GL_FUNCTIONS_#{maj}_#{min}"
  puts "#endif"
end
puts "#undef X", ""

PrintGLVersionsMacro() if $OutputGLBindings

unless $DisableGLLoaderOut
  puts <<LOADER
#if !defined(NULL)
#define NULL ((void*)0)
#endif

#if defined(CWCGL_WINDOWS) || defined(__CYGWIN__)
#ifndef _WINDOWS_
#undef APIENTRY
#endif
#include <windows.h>
typedef void* (APIENTRYP PFNWGLGETPROCADDRESSPROC_PRIVATE)(const char*);
static PFNWGLGETPROCADDRESSPROC_PRIVATE glLoaderGetProcAddressPtr;
static HMODULE libGL = NULL;

#ifdef _MSC_VER
#ifdef __has_include
#if __has_include(<winapifamily.h>)
#define HAVE_WINAPIFAMILY 1
#endif
#elif _MSC_VER >= 1700 && !_USING_V110_SDK71_
#define HAVE_WINAPIFAMILY 1
#endif
#endif

#ifdef HAVE_WINAPIFAMILY
#include <winapifamily.h>
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) && WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
#define IS_UWP 1
#endif
#endif

static int LoadGLLibrary(void) {
#ifndef IS_UWP
    if ((libGL = LoadLibraryW(L"opengl32.dll"))) {
        void(*tmp)(void);
        tmp = (void(*)(void)) GetProcAddress(libGL, "wglGetProcAddress");
        glLoaderGetProcAddressPtr = (PFNWGLGETPROCADDRESSPROC_PRIVATE)tmp;
        return glLoaderGetProcAddressPtr != NULL;
    }
#endif
    return 0;
}

static void CloseGLLibrary(void) {
    if (libGL) {
        FreeLibrary((HMODULE)libGL);
        libGL = NULL;
    }
}
#else
#include <dlfcn.h>
#if !defined(CWCGL_MAC) && !defined(__HAIKU__)
typedef void* (APIENTRYP PFNGLXGETPROCADDRESSPROC_PRIVATE)(const char*);
static PFNGLXGETPROCADDRESSPROC_PRIVATE glLoaderGetProcAddressPtr;
#endif
static void* libGL = NULL;

static int LoadGLLibrary(void) {
#if defined(CWCGL_MAC)
    static const char *NAMES[] = {
        "../Frameworks/OpenGL.framework/OpenGL",
        "/Library/Frameworks/OpenGL.framework/OpenGL",
        "/System/Library/Frameworks/OpenGL.framework/OpenGL",
        "/System/Library/Frameworks/OpenGL.framework/Versions/Current/OpenGL"
    };
#else
    static const char *NAMES[] = {"libGL.so.1", "libGL.so"};
#endif

    unsigned int index = 0;
    for (index = 0; index < (sizeof(NAMES) / sizeof(NAMES[0])); index++) {
        if ((libGL = dlopen(NAMES[index], RTLD_NOW | RTLD_GLOBAL))) {
#if defined(CWCGL_MAC) || defined(__HAIKU__)
            return 1;
#else
            glLoaderGetProcAddressPtr = (PFNGLXGETPROCADDRESSPROC_PRIVATE)dlsym(libGL,
                "glXGetProcAddressARB");
            return glLoaderGetProcAddressPtr != NULL;
#endif
        }
    }
    return 0;
}

static void CloseGLLibrary(void) {
    if (libGL) {
        dlclose(libGL);
        libGL = NULL;
    }
}
#endif

static void* LoadGLProc(const char *namez) {
    void* result = NULL;
    if (libGL == NULL)
        return NULL;

#if !defined(CWCGL_MAC) && !defined(__HAIKU__)
    if (glLoaderGetProcAddressPtr)
        result = glLoaderGetProcAddressPtr(namez);
#endif
    if (!result) {
#if defined(CWCGL_WINDOWS) || defined(__CYGWIN__)
        result = (void*)GetProcAddress((HMODULE)libGL, namez);
#else
        result = dlsym(libGL, namez);
#endif
    }

    return result;
}

#define X(T, N) \\
    if (!(__##N = (T)LoadGLProc(#N))) \\
        failures++;
static int failures = 0;
int InitOpenGL(void) {
    int result = 0;
    if (LoadGLLibrary()) {
LOADER

  $functions.each do |k, v|
    maj, min = k.split '.'
    puts "#if CWCGL_VERSION >= GL_VERSION_#{maj}_#{min}"
    puts "GL_FUNCTIONS_#{maj}_#{min}"
    puts "#endif"
  end

  puts <<LOADER_FOOTER
        result = failures == 0;
        CloseGLLibrary();
    }
    return result;
}
#undef X

LOADER_FOOTER
end

if $DisableWrapperOut
  RestoreOriginalOut()
  exit 0
end

puts <<CONTEXT
static void PushCommand(GLcontext *context, GLcommand *command) {
     // TODO
}
CONTEXT

# Generate command data structures and wrapper functions for each OpenGL function

$functions.each do |k, v|
  maj, min = k.split '.'
  puts "#if CWCGL_VERSION >= GL_VERSION_#{maj}_#{min}"
  v.each do |vv|
    key = vv[1]
    cmd = commands[key]
    argsVoid = (cmd[:params].length == 1 and cmd[:params][0] == "void")
    returnsVoid = cmd[:result] == "void"
    if not argsVoid
      puts "typedef struct {"
      cmd[:params].each do |vvv|
        puts "    #{vvv};"
      end
      unless returnsVoid
        puts "    #{cmd[:result]}* return_value;"
      end
      puts "} cwc#{key}CommandData;", ""
    else
      if not returnsVoid
        puts "typedef struct {"
        puts "    #{cmd[:result]}* return_value;"
        puts "} cwc#{key}CommandData;", ""
      end
    end
    params = cmd[:params].join ", "
    noParams = params == "void"
    returnValue = returnsVoid ? "" : ", #{cmd[:result]}* return_value"
    puts "void cwc#{key}(GLcontext *context#{noParams ? "" : ", " + params}#{returnValue}) {"
    puts "    GLcommand* command = malloc(sizeof(GLcommand));"
    hasParams = (not noParams or (not returnsVoid and argsVoid))
    if hasParams
      puts "    cwc#{key}CommandData* command_data = malloc(sizeof(cwc#{key}CommandData));"
      if not argsVoid
        cmd[:params].each do |vv|
          vvv = vv.split(' ')[-1]
          puts "    command_data->#{vvv} = #{vvv};"
        end
      end
      unless returnsVoid
        puts "    command_data->return_value = return_value;"
      end
    end
    puts "    command->type = cwc#{key}Command;"
    if hasParams
      puts "    command->data = command_data;"
    else
      puts "    command->data = NULL;"
    end
    puts "    PushCommand(context, command);"
    puts "}"
  end
  puts "#endif"
end


# Define function to free commands
puts "static void FreeCommand(GLcommand* command) {"
puts "    switch (command->type) {"
commands.each do |k, v|
  argsVoid = v[:params].length == 1 and v[:params][0] == "void"
  returnsVoid = v[:result] == "void"
  if not returnsVoid or not argsVoid
    puts "        case cwc#{k}Command:"
  end
end
puts "            free(command->data);"
puts "        default:"
puts "            free(command);"
puts "            break;"
puts "    }"
puts "}", ""

# Define function to process commands back to OpenGL function
puts "static void ProcessCommand(GLcommand* command) {"
puts "    switch (command->type) {"

$functions.each do |k, v|
  maj, min = k.split '.'
  puts "#if CWCGL_VERSION >= GL_VERSION_#{maj}_#{min}"
  v.each do |vv|
    key = vv[1]
    cmd = commands[key]

    argsVoid = (cmd[:params].length == 1 and cmd[:params][0] == "void")
    returnsVoid = cmd[:result] == "void"
    closeBrace = true
    if argsVoid and returnsVoid
      puts "        case cwc#{key}Command:"
      puts "            #{key}();"
      closeBrace = false
    else
      puts "        case cwc#{key}Command: {"
      puts "            cwc#{key}CommandData* command_data = (cwc#{key}CommandData*)command->data;"
      params = unless argsVoid
                 cmd[:params].map do |p|
                   "command_data->" + p.split(" ")[-1]
                 end.join ", "
               else
                 ""
               end
      unless returnsVoid
        puts "            if (command_data->return_value)"
        puts "                *(command_data->return_value) = #{key}(#{params});"
        puts "            else"
        puts "                #{key}(#{params});"
      else
        puts "            #{key}(#{params});"
      end
    end
    puts "            break;"
    puts "        }" if closeBrace
  end
  puts "#endif"
end
puts "        default:"
puts "            break;"
puts "    }"
puts "}", ""

RestoreOriginalOut() if $DisableWrapperOut
