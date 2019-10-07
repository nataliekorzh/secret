#include "getnum.h"
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int main() {
        while ((c = getchar()) != EOF) {
                long hexal = getnum();
		int count = 0;
		if (hexal == 0 && count == 0 && validitycounter == 0) {
			valid = true;
		}
                if (valid) {
                        int hex[1000];
                        while (hexal) {
				int ch = hexal%16;
				if (ch > 9) {
					hex[count] = (ch - 10) + 'a';
				} else {
					hex[count] = ch;
				}
                                hexal/=16;
                                count++;
                        }
                        if (negative) {
                                printf("-");
                        }
			printf("0x");
			if (hexal == 0 && count == 0) {
				printf("0");
			}
                        for(int i = count - 1; i >= 0; i--) {
				if (hex[i] > 9) {
					printf("%c", hex[i]);
				} else {
					printf("%d", hex[i]);
				}
                        }
                } else {
                        printf("INVALID");
                	return 0;
		}
        	printf("\n");
	}
}
