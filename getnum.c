#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

int c = 0;
int number[100];
int counter = 0;
bool valid = true;

long binaryReader()
{
        long binary = 0;
        double base = pow((double)2, counter-1);
        for(int i = 0; i < counter; i++) {
                binary += number[i] * base;
                base /= 2;
        }
	return binary;
}


long decimalReader() {
        long decimal = 0;
	double base = pow((double)10, counter-1);
        for(int i = 0; i < counter; i++) {
		decimal += number[i] * base;
		base /= 10;
        }
	return decimal;
}

long getnum(void) {
	if (c == '0') {
		//if first character 0
		c = getchar();
		if(c == 'b') {
			//first two char 0b = binary
			c = getchar();
			while (c == '0' || c == '1'){
				number[counter] = (c-'0');
				counter++;
				c = getchar();
			}

			if (!isspace(c)) {
				valid = false;
				return 0;
			} else {
				return binaryReader();
			}
					
		} else if (c == 'x') {
			//first two char 0x = hex
		
		} else {
			//first char 0 = check if octal
		} 
	} else {
		if (isdigit(c)) {
			//first character is nonzero = decimal
			while (isdigit(c)) {
				number[counter] = (c-'0');
				counter++;
				c = getchar();
			}

			if (!isspace(c)) {
				//exited bc not digit
				valid = false;
				return 0;
			} else {
			//actually read number
				return decimalReader();	
			}
		}
	}
}

