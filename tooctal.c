#include "getnum.h"
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int main() {
        while ((c = getchar()) != EOF) {
                long octal = getnum();
		int count = 0;
		if (octal == 0 && count == 0 && validitycounter == 0) {
			valid = true;
		}
                if (valid) {
                        int oct[1000];
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
                	return 0;
		}
        	printf("\n");
	}

}
