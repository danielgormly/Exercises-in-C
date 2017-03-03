#include <cs50.h>
#include <stdio.h>

int main(void)
{
	printf("Water usage calculator\n\n");
	printf("Shower time: ");
	int shower_time = get_int();
	printf("Minutes: %i\nBottles: %i\n", shower_time,  shower_time * 12);
}
