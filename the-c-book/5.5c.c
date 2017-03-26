// Exercise 5.5c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 10

char *getstr(void);
char *indexOfSubString(char *subString, char *searchString);


int main(void) {
    printf("Exercise 5.5c Index of (case sensitive, max-string len: %i)\n\n", STR_LEN);
    printf("Enter subString: ");
    char *subString = getstr();
    printf("Enter search string: ");
    char *searchString = getstr();
    char *val = indexOfSubString(subString, searchString);
    printf("Result: %s\n", val);
    return EXIT_SUCCESS;
}

char *getstr() {
    int c;
    char *cur = (char *)malloc(STR_LEN);
    char *result = cur;
    
    while((c = getchar()) != '\n' && c!= EOF) {
        if(cur - result < STR_LEN - 1) {
            *cur++ = c;
        }
    }
    *cur = 0;
    return result;
}

char *indexOfSubString(char *subString, char *searchString) {
    int match = 0;
    char *_searchString = searchString;
    
    while(*_searchString != 0) {
        char *se = _searchString;
        char *su = subString;
        while(*se == *su) {
            ++se;
            if (*(++su) == 0) {
                match = 1;
                break;
            }
        }
        if (match == 1) return _searchString;
        _searchString++;
    }
    return 0;
}