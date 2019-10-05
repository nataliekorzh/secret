#include <stdio.h>
#include <ctype.h>

int main () {
	int letters[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 

	int c = 0;

	while ((c = getchar()) != EOF) {
		if (isalpha(c)) {
			char letter = tolower(c);
			int index = letter - 'a';
			letters[index] += 1;
		}
	}

	double total = 0;
	
	for (int i = 0; i < 26; ++i) {
		total += letters[i];
	}

	printf("Character \t Count \t\t Frequency (%%) \n"); 
	
	for(int i=0; i<26; i++){
		int character = i + 'a';
		int count = letters[i];
		double freq = (count / total) * 100;
		printf("%c \t\t  %d \t\t %f\n", character, count, freq);
	}
}
