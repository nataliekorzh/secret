CC := clang
CFLAGS := -std=c11 -Wall

.PHONY: all clean check
all: frequency encode_bits decode_bits todecimal

clean:

frequency.o: frequency.c
	$(CC) $(CFLAGS) -c frequency.c

frequency: frequency.o
	$(CC) $(CFLAGS) -o frequency frequency.o

encode_bits: encode_bits.c bits.o
	$(CC) $(CFLAGS) -c encode_bits.o encode_bits.c
	$(CC) $(CFLAGS) -o encode_bits bits.o encode_bits.o

decode_bits: decode_bits.c bits.o
	$(CC) $(CFLAGS) -c decode_bits.c
	$(CC) $(CFLAGS) -o decode_bits bits.o decode_bits.o

getnum.o: getnum.c
	$(CC) $(CFLAGS) -c getnum.c

todecimal: getnum.o todecimal.c
	$(CC) $(CFLAGS) -c todecimal.c
	$(CC) $(CFLAGS) -o todecimal getnum.o todecimal.o -lm

bits.o: bits.c
	$(CC) $(CFLAGS) -c bits.c

check: all
	./tests/run_tests
