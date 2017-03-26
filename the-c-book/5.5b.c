// Exercise 5.5b

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 10

char *getstr(void);
char *indexOf(char character, char *string);


int main(void)
{
    printf("Exercise 5.5b Index of (case sensitive, max-string len: %i)\n\n", MAX_LEN);
    printf("Enter string: ");
    char *string = getstr();
    printf("Enter character to search for: ");
    char character = getchar();
    indexOf(character, string);
    return EXIT_SUCCESS;
}

char *getstr() {
    int c;
    char *cur = (char *)malloc(MAX_LEN);
    char *result = cur;
    
    while((c = getchar()) != '\n' && c!= EOF) {
        if(cur - result < MAX_LEN - 1) {
            *cur++ = c;
        }
    }
    *cur = 0;
    return result;
}

char *indexOf(char character, char *string) {
    char *cur = string;
    
    while(*cur != character && *cur != 0) {
        cur++;
    }
    if(*cur == 0) {
        printf("indexOf: character not found in string, returning null pointer\n");
        return 0;
    }
    printf("indexOf: character found in string at position %i, returning pointer to char in string\n", (int)(cur - string));
    return cur;
}