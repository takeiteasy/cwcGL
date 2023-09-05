puts File.read("src/cwcgl.h")
puts ""
puts "#if defined(CWCGL_IMPLEMENTATION)"
File.readlines("src/cwcgl.c").each do |line|
    if line =~ /^#include "backends\/cwcgl_(\S+)\.c"$/
        puts File.read("src/backends/cwcgl_#{$1}.c")
    else
        puts line unless line =~ /^#include "cwcgl.h"$/
    end
end
puts "#endif"
