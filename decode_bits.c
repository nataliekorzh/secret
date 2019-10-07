#include <stdio.h>
#include "bits.h"
int main () {
	char current = 0;
	while ((current = getchar()) != EOF) {
		decode_bits(current);
                if ((counter > 0) && counter % CHAR_BIT == 0 && !whitespace) {
			int total = 0;
			int decoder = 128;
                        for(int i = 0; i < CHAR_BIT; i++) {
                                total += charbin[i]*decoder;
                                decoder/=2;
                        }
			putchar(total);
		}
	}

}
