#include <stdio.h>
#include "bits.h"

int main () {
	char current = 0;

	while ((current = getchar()) != EOF) {
		print_bits(current);
	}

	printf("\n");
}
