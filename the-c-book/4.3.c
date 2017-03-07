// Exercise 4.3 The C Book

#include <stdio.h>
#include <stdlib.h>

static int line_number = 0;
static int col_number = 0;

// Definition
int output(char a) {
    switch (a) {
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

int current_line(void) {
    return line_number;
}

int current_column(void) {
    return col_number;
}