#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

char * getString(void);
char * toInitials(char *);
char toUpper(char);

int main(void)
{
	printf(
		"CS50 Fall 2016 Problem Set 2\n"
		"Exercise 1: Initials (More comfortable)\n"
		"Type name (max chars: 100, max words: 10): "
	);
	char *name = getString();
	printf("Returned string: %s\n", name);
	char *initials = toInitials(name);
	printf("Initials: %s\n", initials);
	return EXIT_SUCCESS;
}

char * getString(void) {
	int c;
	char *string = malloc(sizeof *string * MAXLEN);
	char *cur = string;
	
	while((c = getchar()) != '\n' && c != EOF) {
		if(cur - string < MAXLEN - 2) {
			*cur++ = c;
		}
	}
	*cur = '\0'; // Terminate string
	
	return string;
}

char * toInitials(char *string) {
	printf("Input string: %s\n", string);
	char *stringChar = string;
	char *initials = malloc(sizeof *initials * MAXLEN);
	char *initialsChar = initials;
	
	while(*stringChar != '\0') {
		if ((stringChar - string == 0 || *(stringChar-1) == ' ') && initialsChar - initials < 10) {
			*initialsChar = toUpper(*stringChar);
			initialsChar++;
		}
		stringChar++;
	}
	*initialsChar = '\0';
	
	return initials;
}

char toUpper(char letter) {
	char caseDiff = 'A' - 'a';
	if (letter >= 'a' && letter <= 'z') {
		return letter + caseDiff;
	}
	return letter;
}