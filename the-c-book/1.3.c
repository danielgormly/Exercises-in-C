#include <stdio.h>
#include <stdlib.h>

// The C Book Exercise 1.3

int isAbsDigitChar(int value);
int getIntIt(void); // Iterator
int getInt(); // Generator
int zero = (int) '0';

int main(void)
{
	int value = getInt();
	printf("Integer value: %i\n", value);
}
int isAbsDigitChar(int value) {
	return value > zero && value < zero + 9 ? 1 : 0;
}
int getIntIt() {
	int validInput = 0;
	int atChar = 0;
	int maxLen = 10;
	char input[maxLen];
	int currentChar;
	int stop = 0;
	while (	validInput == 0 && atChar <= maxLen - 1 && stop == 0 ) {
		currentChar = getchar();
		if(currentChar == '\n' && atChar == 0) validInput = -1;
		else if(!isAbsDigitChar(currentChar) && currentChar != '\n' ) validInput = -1;
		else if (currentChar == '\n') {
			stop = 1;
			input[atChar] = '\0';
		} else {
			input[atChar] = currentChar;
			atChar++;
		}
	}
	if (validInput == -1) {
		printf("Not an integer.\n");
		int c;
		while((c = getchar()) != '\n' && c != EOF ) { } // Flush remaining input
		return -1;
	}
	int result;
	sscanf(input, "%d", &result);
	return result;
}
int getInt() {
	int validAbsInt = -1;
	while(validAbsInt == -1) {
		printf("Enter a valid, absolute integer: ");
		validAbsInt = getIntIt();
	}
	return validAbsInt;
}
