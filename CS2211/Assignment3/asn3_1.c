/* Yimin Xu 250876566
   Computer Science 2211B
   Assignment 3 
   Part 1
*/
#include <stdio.h>

/* Functions */
float s_exp(float sub_exp, char op);
char get_op();
float get_num();

/* Main */
int main(void)
{
	char cont = 'Y';
	while (cont == 'Y' || cont == 'y')
	{
		printf("Enter a simple arithmetic expression: ");
		float result = s_exp(get_num(),get_op()); 
		/* Use the recursive function to calculate the result */

		printf(" The result is %f\n", result);

		printf("Do you want to continue? Y/N\n");
		scanf("%c",&cont);
		/* Enter Y or y to continue, otherwise to quit */
	}
}

// Input: ’sub_exp’: the value of the sub expression to the left of ’op’
//        ’op’ : an operator, + or -
//        the rest of the expression will be read in from stdin
// Effect: the whole expression is evaluated using recursion:
//         get next_num and then get next_op of the expression
//         use ’sub_exp op next_num’ and ’next_op’ to do recursive call
// Output: this function returns the value of the expression
float s_exp(float sub_exp, char op) 
{
	if (op == '\n')
		return sub_exp;
	else if (op == '+')
		return s_exp(sub_exp + get_num(), get_op());
	else if (op == '-')
		return s_exp(sub_exp - get_num(), get_op());
	else
	{
		printf("Invalid operator.\n");
		return 0;
	}
}

// Input: none, read from stdin
// Effect: get the next operator of the expression
//         this operator can be +, -, or ’\n’
//         ’\n’ indicates the end of the expression input
//         leading spaces should skipped
// Output: return the next operator of the expression.
char get_op() 
{
	char op = ' ';
	while (op == ' ')
		scanf("%c", &op);
	return op;
}

// Input: none, read from stdin
// Effect: get the next numeric value of the expression
// Output: return the next numeric value of the expression.
float get_num() 
{
	float num;
	scanf("%f", &num);
	return num;
}
