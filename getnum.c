#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

int c = 0;
int number[100];
int counter = 0;
bool valid = true;
bool negative = false;
bool at_eof = false;
int validitycounter = 0;

static bool in_range(int base, bool negative, long result, int next)
{
        if(negative) {
                if (result >= (LONG_MIN + next) / 10) {
                        return true;
                } else {
                        valid = false;
                        return false;
                }
        } else {
                if (result >= (LONG_MAX - next) / 10) {
                        return true;
                } else {
                        valid = false;
                        return false;
                }
        }
}

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

//long decimalReader() {
//        long long decimal = 0;
//        for(int i = 0; i < counter; i++) {
//                if(in_range(10, negative, decimal, number[i])){
  //                      if(!negative){

                                //printf("decimal = 10 * %d + %d \n", decimal, number[i]);
//                                decimal = 10LL * decimal + number[i];
  //                      }else{
                                //printf("decimal = 10 * %d - %d \n", decimal, number[i]);
    //                            decimal = 10LL * decimal - number[i];

      //                  }
        //        }
      //  }
//        return decimal;
//}

long octalReader() { 
	long octal = 0;
	double base = pow((double)8, counter-1);
	for(int i = 0; i < counter; i++) {
		octal += number[i] *base;
		base /= 8;
	}
	return octal;
}

long hexReader() {
        long hexidecimal = 0;
        double base = pow((double)16, counter-1);
        for(int i = 0; i < counter; i++) {
                hexidecimal += number[i] *base;
                base /= 16;
        }
        return hexidecimal;
}



long getnum(void) {
	if (c == '-') {
		negative = true;
		c = getchar();
	}
		
	if (c == '0') {
		//if first character 0
		validitycounter = 0;
		c = getchar();
		if(c == 'b') {
			++validitycounter; // =2 if more
			//first two char 0b = binary
			c = getchar();
			valid = false;
			while (c == '0' || c == '1'){
				valid = true;
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
			++validitycounter;
			//first two char 0x = hex
			c = getchar();
			valid = false;
			while (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' ||c == '6' || c == '7' || c == '8' ||  c == '9' || c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F'){
				valid = true;
				if(isdigit(c)){
					number[counter] = c-'0';
					counter++;
					c = getchar();
				} else if (isalpha(c)){
					if (c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f') {
						number[counter] = (c-'a') + 10;
						counter++;
						c = getchar();
					} else {
						number[counter] = (c - 'A') + 10;
						counter++;
						c = getchar();
					}
				}
			}
			if (!isspace(c)) {
				valid = false;
				return 0;
			} else {
				return hexReader();
			}
		} else {
			//first char 0 = check if octal
			valid = false;
			++validitycounter;
			while(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' ||c == '6' || c == '7'){
				valid = true;
				number[counter] = c-'0';
				counter++;
				c = getchar();
			} 
			if (!isspace(c)){
				valid = false;
				return 0;
			} else { 
				return octalReader();
			}
		}

	} else {
		if (isdigit(c)) {
			//first character is nonzero = decimal
			valid = false;
			while (isdigit(c)) {
				valid = true;
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
		} else {
			//not anything
			valid = false;
			return 0;
		}
	}
}

