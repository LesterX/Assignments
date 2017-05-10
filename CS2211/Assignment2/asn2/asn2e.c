#include <stdio.h>
//Yimin Xu 
//250876566

//Exponential Calculator
float exp_calculator(float b,int e)
{
	float base = b;
	int exponent = e;
	if (e < 0)
	{
		printf("Please enter positive exponent.");
		return 0;
	}
	else if (e == 0)
		return 1;
	else if (e == 1)
		return base;
	else if (e % 2 == 0)
		return (exp_calculator(base, e / 2) * exp_calculator(base, e / 2));
	else
		return (exp_calculator(base, e / 2) * exp_calculator(base, e / 2) * base);
}

int main(void)
{
	float base;
	int exponent;
	printf("Enter the base: ");
	scanf(" %f", &base); //Read the base input
	printf("Enter the 'positive' exponent: ");
	scanf(" %d", &exponent); // Reade the exponent input

	printf("\n%f ^ %d = %f\n", base, exponent, exp_calculator(base, exponent));
}
