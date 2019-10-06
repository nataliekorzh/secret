#include <stdio.h>
#include <limits.h>
#include <ctype.h>

int counter = 0;
int charbin[CHAR_BIT];
int charcounter = 0;

void print_bits(int ch) {
	int binary[CHAR_BIT];
   	for(int i = 0; i < CHAR_BIT; i++) {
        	binary[i] = ch%2;
        	ch/=2;
    	}
	
	for(int i = (CHAR_BIT - 1); i >= 0; i--) {
		charcounter++;
		printf("%d", binary[i]);
    		if ((charcounter > 0)&& (charcounter%70 == 0)) {
			//70 characters - need new line
			printf("\n");
		}	
	}
}

void decode_bits(int ch) {
	if ((ch != ' ') && (ch != '\v') && (ch != '\t') && (ch != '\r') && (ch != '\f')) {
		int decoder = 128;
		int total = 0;
		if ((counter > 0) && counter % CHAR_BIT == 0) {
			for(int i = 0; i < CHAR_BIT; i++) {
				total += charbin[i]*decoder;
				decoder/=2;
			}
			decoder = 128;
			putchar(total);
		} else {
			if (counter%CHAR_BIT < CHAR_BIT) {
                		charbin[counter%CHAR_BIT] = ch-'0';
			}
		}
		counter++;
	}
       	if (ch != '0' && ch != '1') {
		fprintf(stderr, "Character: %c is not a '0' or '1'", ch);
	}	
}
