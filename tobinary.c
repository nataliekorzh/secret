#include "getnum.h"
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int main() {
        while ((c = getchar()) != EOF) {
                long bin = getnum();
		bool one = false;
		int count = 0;
		if (bin == 0 && count == 0 && validitycounter == 0) {
			valid = true;
		}
                if (valid) {
			int binary[1000];
			while(bin) {
        			binary[count] = bin%2;
        			bin/=2;
				count++;
    			}

			if (negative) {
				printf("-");
			}

			printf("0b");
        		for(int i = count - 1; i >= 0; i--) {
                		if (binary[i] == 1 || (binary[i] == 0 && one == true)) {
					one = true;
					printf("%d", binary[i]);
				}
			}
                        if (one == false && count == 0)
                        {
                                printf("0");
                        }
                } else {
                        printf("INVALID");
                        return 0;
      		}
		printf("\n");
	}
}  
