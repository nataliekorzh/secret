#include "getnum.h"
#include <stdio.h>
#include <limits.h>

int main() {
        while ((c = getchar()) != EOF) {
                long octal = getnum();
                if (valid) {
                        int oct[1000];
			int count = 0;
                        while (octal) {
                                oct[count] = octal%8;
                                octal/=8;
				count++;
                        }
			if (negative) {
				printf("-");
			}
                        for(int i = count; i >= 0; i--) {
                                printf("%d", oct[i]);
                        }
                } else {
                        printf("INVALID");
                }
        }
}
