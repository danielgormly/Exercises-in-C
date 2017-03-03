#include <cs50.h>
#include <stdio.h>
#include <math.h>

long long getCC();
int addOddDigits();
int addDigits();
int addEvenDigits();
int len();

int main(void)
{
	printf("CC validator \n\n");
	long long cc_number = getCC();
	int sum1 = addOddDigits(cc_number);
	int sum2 = addEvenDigits(cc_number);
	printf("%i", sum1 + sum2);
}
int len(long long cc_number)
{
	return floor(log10(llabs(cc_number))) + 1;
}
long long getCC()
{
	printf("Enter CC number: ");
	long long cc_number = get_long_long();
	int cc_size = len(cc_number);
    switch (cc_size) {
        case 13:
        case 15:
        case 16:
            return cc_number;
        default:
            printf("Invalid credit card number\nPlease enter a valid credit card number: ");
            return getCC();
    }
}
int addDigits(int num)
{
	if (num < 10) return num;
	if (num == 10) return 1;
	return 1 + num - 10;
}
int addEvenDigits(long long cc_number)
{
	int result = 0;
	for(int i = 0; i < len(cc_number); i += 2)
	{
		result += cc_number / (long long) pow(10, i) % 10;
	}
	return result;
}
int addOddDigits(long long cc_number)
{
	int result  = 0;
	for(int i = 1; i < len(cc_number); i += 2)
	{
		result += addDigits((cc_number / (long long) pow(10, i)) % 10 * 2);
	}
	return result;
}
