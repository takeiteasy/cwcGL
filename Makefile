ifeq ($(OS),Windows_NT)
	LIBEXT=dll
	PROGEXT=.exe
else
	UNAME:=$(shell uname -s)
	PROGEXT=
	ifeq ($(UNAME),Darwin)
		LIBEXT=dylib
		HOST_LINKER:=$(shell pkg-config --libs glfw3) -framework OpenGL -framework Cocoa -framework IOKit
		HOST_CFLAGS:=$(shell pkg-config --cflags glfw3) -DGL_SILENCE_DEPRECATION
	else ifeq ($(UNAME),Linux)
		LIBEXT=so
		HOST_LINKER:=$(shell pkg-config --libs glfw3) -lGL -ldl
		HOST_CFLAGS:=$(shell pkg-config --cflags glfw3)
	else
		$(error OS not supported by this Makefile)
	endif
endif

DEBUG?=0
CFLAGS:=-g -Wall -Isrc
ifeq ($(DEBUG),1)
	CFLAGS+=-DCWCGL_DEBUG_VALIDATE
endif

BIN:=build
OUT:=$(BIN)/host$(PROGEXT)

LIB_SRCS:=src/reload.c src/loader.c src/registry.c
TEST_DIR:=test
TEST_TARGETS:=$(patsubst $(TEST_DIR)/%.c,$(BIN)/%.$(LIBEXT),$(filter-out $(TEST_DIR)/host.c,$(wildcard $(TEST_DIR)/*.c)))

default: $(OUT)

$(BIN):
	mkdir -p $(BIN)

$(OUT): test/host.c $(LIB_SRCS) | $(BIN)
	$(CC) $(CFLAGS) $(HOST_CFLAGS) -o $@ test/host.c $(LIB_SRCS) $(HOST_LINKER)

FORCE: ;

$(BIN)/%.$(LIBEXT): $(TEST_DIR)/%.c src/client.c FORCE | $(BIN)
	$(CC) $(CFLAGS) -shared -fPIC -fvisibility=hidden -o $@ $< src/client.c

tests: $(TEST_TARGETS)

all: $(OUT) tests

run: $(OUT) tests
	./$(OUT) $(BIN)/leak_test.$(LIBEXT)

clean:
	$(RM) -r $(BIN)

.PHONY: default all tests run clean FORCE
