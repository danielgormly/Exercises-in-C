#include <stdio.h>
#include <stdlib.h>

// Exercise 4.3 The C Book
// Output defined in 4.3.c

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
    printf("At line #: %i, col #: %i", current_line(), current_column());
    return EXIT_SUCCESS;
}