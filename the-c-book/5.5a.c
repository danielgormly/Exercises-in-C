// Exercise 5.5a

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 10

char *getstr(void);
int compstr(char *str1, char *str2);

int main(void)
{
    printf("Exercise 5.5a String compare (case sensitive)\n");
    printf("Enter string 1: ");
    char *str1 = getstr();
    printf("\nEnter string 2: ");
    char *str2 = getstr();
    int val = compstr(str1, str2);
    printf("The input strings are ");
    fputs(val ? "equal" : "not equal", stdout);
    printf("\n");
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

int compstr(char *str1, char *str2) {
    int match = 1;
    char *_str1 = str1;
    char *_str2 = str2;
    for (int i = 0; i < MAX_LEN; i++) {
        if (*_str1++ != *_str2++) {
            match = 0;
            break;
        }
    }
    return match;
}