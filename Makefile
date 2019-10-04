CC := clang
CFLAGS := -std=c11 -Wall

.PHONY: all clean check
all:
 	$(CC) $(CFLAGS) -c -o %.o %.c
clean:

frequency.o: frequency.c frequency.h
	 $(CC) $(CFLAGS) -c -o frequency.o frequency.c

check: all
	./tests/run_tests
