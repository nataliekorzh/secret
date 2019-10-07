#include "getnum.h"
#include <stdio.h>
#include <limits.h>

int main() {
        while ((c = getchar()) != EOF) {
                long hexal = getnum();
                if (valid) {
                        int hex[1000];
                        int count = 0;
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
                        for(int i = count - 1; i >= 0; i--) {
				if (hex[i] > 9) {
					printf("%c", hex[i]);
				} else {
					printf("%d", hex[i]);
				}
                        }
                } else {
                        printf("INVALID");
                }
        }
}
