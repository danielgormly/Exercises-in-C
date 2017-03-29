/* CS50 Problem Set 2 Fall 2016
 * Crack (More comfortable)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crypt.h>

#define MAXPWLEN 4 // Max length of password to check for

int validateArgCount(int);
char * crack();
int check(char *);
void setSalt(char *);

char * inputHash;
char inputSalt[2];

int main(int argc, char *argv[]) {
    if (!validateArgCount(argc)) return EXIT_FAILURE;
    
    inputHash = argv[1];
    setSalt(argv[1]);
    
    printf("Attempting to crack, please be patient :D.\n");
    char *pass = crack(MAXPWLEN);
    if(pass == 0) printf("No password found.");
    printf("Password match!\nPassword: \"%s\"\n", pass);
    
    return EXIT_SUCCESS;
}

char * crack(int maxLength) {
    static int match = 0;
    int place = MAXPWLEN - maxLength;
    static char guess[MAXPWLEN + 1];
    
    for (char letter = 'A'; letter <= 'z' && match == 0; letter++) {
        if(letter > 'Z' && letter < 'a') continue; // Skip symbols to meet specifications only
        guess[place] = letter; // add string
        guess[place + 1] = '\0'; // terminate string
        if (check(guess) || (maxLength > 1 && crack(maxLength - 1))) {
            return guess;
        }
    }
    return 0;
}

int check(char *guess) {
    char guessHashArr[13];
    char *guessHash = guessHashArr;
    guessHash = crypt(guess, inputSalt);
    int match = strcmp(guessHash, inputHash) == 0;
    return match;
}

int validateArgCount(int argc) {
    switch (argc) {
        case 1:
            printf("Crack ran with no arguments. Exiting.\n");
            return 0;
        case 2:
            return 1;
        default:
            printf("Crack ignoring additional arguments.\n");
            return 1;
    }
}
void setSalt(char *hash) {
    inputSalt[0] = *hash;
    inputSalt[1] = *(hash+1);
}