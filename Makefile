CC := clang
CFLAGS := -std=c11 -Wall

.PHONY: all clean check
all: frequency encode_bits decode_bits todecimal tobinary tooctal tohex

clean:

frequency.o: frequency.c
	$(CC) $(CFLAGS) -c frequency.c

frequency: frequency.o
	$(CC) $(CFLAGS) -o frequency frequency.o

encode_bits: encode_bits.c bits.o
	$(CC) $(CFLAGS) -c encode_bits.o encode_bits.c
	$(CC) $(CFLAGS) -o encode_bits bits.o encode_bits.o

decode_bits: decode_bits.c bits.o
	$(CC) $(CFLAGS) -c decode_bits.o decode_bits.c
	$(CC) $(CFLAGS) -o decode_bits bits.o decode_bits.o

getnum.o: getnum.c
	$(CC) $(CFLAGS) -c getnum.c

todecimal: getnum.o todecimal.c
	$(CC) $(CFLAGS) -c todecimal.c
	$(CC) $(CFLAGS) -o todecimal getnum.o todecimal.o -lm

tobinary: getnum.o tobinary.c
	 $(CC) $(CFLAGS) -c tobinary.c
	 $(CC) $(CFLAGS) -o tobinary getnum.o tobinary.o -lm

tooctal: getnum.o tooctal.c
	$(CC) $(CFLAGS) -c tooctal.c
	$(CC) $(CFLAGS) -o tooctal getnum.o tooctal.o -lm

tohex: getnum.o tohex.c 
	$(CC) $(CFLAGS) -c tohex.c
	$(CC) $(CFLAGS) -o tohex getnum.o tohex.o -lm

bits.o: bits.c
	$(CC) $(CFLAGS) -c bits.c

check: all
	./tests/run_tests
