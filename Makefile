default:
	clang tools/test.c src/glWrapper.c src/backends/cwcgl_mac.c -Isrc -framework Cocoa -o build/test

.PHONY: default
