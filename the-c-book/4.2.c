#include <stdio.h>
#include <stdlib.h>

// Exercise 4.2 The C Book

int output(char);

int main(void)
{
    output('\n');
    output('d');
    output('a');
    output('n');
    output('i');
    output('e');
    output('l');
    output(-1);
    output('s');
    output('a');
    output('y');
    output('s');
    output('\n');
    output('h');
    output('i');
    output(-1);
    return EXIT_SUCCESS;
}

// Definition
int output(char a) {
    static int line_number = 0;
    static int col_number = 0;
    switch (a) {
        case -1:
            printf("[At #: %i, col #: %i]", line_number, col_number);
        case '\n': 
            putchar('\n');
            line_number++;
            col_number = 0;
            break;
        default:
            putchar(a);
            col_number++;
            break;
    }
    return EXIT_SUCCESS;
}