#include <cs50.h>
#include <stdio.h>


void print_mario(int height);
void print_block(char character, int times);

int main(void)
{
	printf("Mario, PS1 CS50\n\n");
	int height = get_int();
	print_mario(height);
}

void print_mario(int height) {
	for(int i = 1; i <= height; i++)
	{
		print_block(' ', height - i);
		print_block('#', i);
		printf("  ");
		print_block('#', i);
		print_block(' ', height - i);
		printf("\n");
	}
}

void print_block(char character, int times)
{
	for(int i = 0; i < times; i++)
	{
		printf("%c", character);
	}
}
