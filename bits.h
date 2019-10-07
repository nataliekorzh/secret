#ifndef BITS_H
#define BITS_H
#include <limits.h>
#include <stdbool.h>

extern int counter;
extern int charcounter;
extern int charbin[CHAR_BIT];
void print_bits(int ch);
void decode_bits(int ch);
extern bool whitespace;

#endif
