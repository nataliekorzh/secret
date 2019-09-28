CC := clang
CFLAGS := -std=c11 -Wall

.PHONY: all clean check
all:

clean:

check: all
	./tests/run_tests
