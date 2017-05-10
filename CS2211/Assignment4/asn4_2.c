/*	Computer Science 2211B
	Section 001
	Assignment 4
	Part 2
	Yimin Xu
	250876566	*/
#include <stdio.h>

int factorial(int x);

int main()
{
	double limit, next_add, sum = 1;
	int next = 1;
	next_add = (double) 1 / factorial(next);

	//	Read the input
	printf("Enter a number for limitation: ");
	scanf(" %lf", &limit);

	while (next_add >= limit)
	{
		sum += next_add;
		next ++;
		next_add = (double) 1 / factorial(next);
	}

	//	Something to make the output looks good!
	printf("e = 1");
	int i;
	for (i = 1; i < next; i ++)
		printf(" + (1 / %d!)", i);
	printf(" = %lf\n", sum);

	return 0;
}

//	Input: an integer x
//	Return the factorial of x
int factorial(int x)
{
	if (x < 1)
	{
		puts("Positive number only\n");
		return 0;
	}

	int i, result = 1;

	for (i = x; i > 1; i --)
		result *= i;

	return result;
}
