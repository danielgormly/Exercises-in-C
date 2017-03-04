#include <stdio.h>
#include <stdlib.h>

// The C Book Exercise 1.5
// Gets int with getchar and prints Binary and Hex using modulus technique

int isAbsDigitChar(int value);
int getIntIt(void); // Iterator
int getInt(); // Generator
int zero = (int) '0';
void dispBinary(int n);
void dispHex(int n);

int main(void)
{
	int value = getInt();
	dispBinary(value);
	dispHex(value);
}
int isAbsDigitChar(int value) {
	return value >= zero && value < zero + 9 ? 1 : 0;
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
void dispBinary(int n) {
	int binary = 0;
	int remainder;
	for (int i = 1; n != 0 ; i = i * 10 ) {
		remainder = n % 2;
		n = n / 2;
		binary = binary + (remainder * i);
	}
	printf("Binary: %i\n", binary);
}

void dispHex(int n) {
	char hex[100];
	int i = 0;
	int temp;
	int quotient = n;
	for (; quotient != 0; i++) {
		temp = quotient % 16;
		temp += temp < 10 ? 48 : 55;
		hex[i] = temp;
		hex[i + 1] = '\0';
		quotient /= 16;
	}
	printf("Hex: ");
	for (int j = i - 1; j >= 0; j-- ) {
		printf("%c", hex[j]);
	}
	printf("\n");
}