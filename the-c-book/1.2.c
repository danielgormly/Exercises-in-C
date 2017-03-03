#include <stdio.h>
#include <stdlib.h>

/* The C Book exercise 1.2
 * Prints sequential (differing by 2) pairs of prime numbers
*/

int main(void)
{
	int divisor, notPrime, prev;
	prev = 1;

	for ( int i = 1; i < 1000; i += 2) {
		notPrime = 0;
		divisor = i / 2;
		for (int j = 2; notPrime == 0 && j < divisor; j++) {
			if (i % j == 0) {
				notPrime = 1;
			}
		}
		if (notPrime == 0) {
			if (i == prev + 2) {
				printf("cur: %i,  prev: %i\n", i, prev);
			}
			prev = i;
		}
	}
}
