#include "getnum.h"
#include <stdio.h>

int main() {
	while ((c = getchar()) != EOF) {
		long dec = getnum();
		if (valid) {
			printf("%d", dec);
		} else {
			printf("INVALID");
			return 0;
		}
		printf("\n");
	}
}
