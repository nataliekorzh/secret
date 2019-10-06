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

	printf("Character    Count    Frequency (%%)\n");	
	double max = (letters[0]/total) * 100;
	double min = (letters[0]/total) * 100;
	double maxarr[26];
	double minarr[26] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50};

	for(int i=0; i<26; i++){
		int character = i + 'a';
		int count = letters[i];
		double freq = (count / total) * 100;
		if (total == 0) {
			freq = 0;
		}

		printf("%c         %8d    %13.3f\n", character, count, freq);
		if (freq >= max) {
			//current character has higher frequency
			maxarr[i] = freq; //add to max array at index of letter and value of freq
			max = freq;
		}
		
		if (freq <= min) {
			//current character has lower freq
			minarr[i] = freq; //add to min array at index i w value freq
			min = freq;
		}
	}

	//find max and mins official
	for (int i=0; i<26; i++) {
		double maxfreq = maxarr[i];
		if (maxfreq < max) {
			maxarr[i] = 0;
		}

		double minfreq = minarr[i]; 
		if (minfreq > min) { 
			minarr[i] = 50;
		}
	}

	//print max and min
	printf("Most frequent: ");
	for (int i=0; i<26; i++) {
		if (maxarr[i] != 0) {
			printf("%c ", i + 'a');
		}
	}
	printf("\n");

	//print min
	printf("Least frequent: ");
	for (int i=0; i<26; i++) {
		if (minarr[i] != 50) {
			printf("%c ", i + 'a');
		}
	}
	printf("\n");
}
