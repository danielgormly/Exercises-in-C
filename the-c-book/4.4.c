// Exercise 4.4 The C Book

#include <stdio.h>
#include <stdlib.h>

int recurse(void);

int main(void) {
    recurse();
    return EXIT_SUCCESS;
}

int recurse(void) {
    static int i = 100;
    printf("%i\n", i--);
    if(i > 0) recurse();
    return EXIT_SUCCESS;
}