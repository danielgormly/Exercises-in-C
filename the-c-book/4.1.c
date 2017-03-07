#include <stdio.h>

// Exercise 4.1 The C Book

// Declaration & Prototype
int abs_val(int);

int main(void)
{
    printf("%i", abs_val(-3));
    printf("%i", abs_val(-4));
    printf("%i", abs_val(5));
    printf("%i", abs_val(6));
}

// Definition
int abs_val(int val) {
    return val >= 0 ? val : -val;
}