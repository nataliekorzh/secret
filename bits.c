#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

int counter = 0;
int charbin[CHAR_BIT];
int charcounter = 0;
bool whitespace = false;

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
	if (isspace(ch)) {
		whitespace = true;
		return;
	} else if (ch == '0' || ch == '1'){
		charbin[counter%CHAR_BIT] = ch-'0';
		counter++;
		whitespace = false;
	} else {
		fprintf(stderr, "Character '%c' is not '0' or '1'", ch);
	}	
}
