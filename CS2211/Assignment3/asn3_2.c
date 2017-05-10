/* Yimin Xu 250876566
   Computer Science 2211B
   Assignment 3 
   Part 2
*/

#include <stdio.h>

/* Main */
int main(void)
{
	/* Building the 3-dimensional array */
	const char seg[10][3][3] = {{{' ','_',' '},{'|',' ','|'},{'|','_','|'}},
		{{' ',' ',' '},{' ',' ','|'},{' ',' ','|'}}, 
		{{' ','_',' '},{' ','_','|'},{'|','_',' '}},
		{{' ','_',' '},{' ','_','|'},{' ','_','|'}},
		{{' ',' ',' '},{'|','_','|'},{' ',' ','|'}},
		{{' ','_',' '},{'|','_',' '},{' ','_','|'}},
		{{' ','_',' '},{'|','_',' '},{'|','_','|'}},
		{{' ','_',' '},{' ',' ','|'},{' ',' ','|'}},
		{{' ','_',' '},{'|','_','|'},{'|','_','|'}},
		{{' ','_',' '},{'|','_','|'},{' ','_','|'}}};

	char cont = 'Y';
	while (cont == 'Y' || cont == 'y')
	{
		int num[100];
		int input_num; /* The input integer */
		printf("Enter an integer: ");
		scanf(" %d", &input_num);
		int neg, len = 0;

		/* Put different labels on negative number, 0, and positive number */
		if (input_num < 0) 
		{
			neg = -1;
			input_num = 0 - input_num;
		}else if (input_num == 0)
			neg = 0;
		else
			neg = 1;	

		/* Split the integer into single numbers into the array and count the size */
		while (input_num != 0)
		{
			num[len] = input_num % 10;
			input_num = input_num / 10;
			len ++;
		}

		/* The last number is always zero and we should ignore that */
		len --;

		if (neg == 0) /* Zero was not included when spliting the integer */
		{
			int p, q;
			for (p = 0; p < 3; p ++)
			{
				for (q = 0; q < 3; q ++)
					printf("%c", seg[0][p][q]);
				printf("\n");
			}
		}else
		{
			int a,l,b;
			for (a = 0; a < 3; a ++)
			{
				/* When the number is negative, put '_' (negative) in the second line 
				   and a single space in other lines */
				if (neg == -1)
				{	if (a == 1)
						printf("_");
					else 
						printf(" ");
				}	
				
				/* Read the array from the last number (excluding the last zero) */
				for (l = len; l >= 0; l --)
				{
					for (b = 0; b < 3; b ++)
						printf("%c",seg[num[l]][a][b]);
				}
				printf("\n");
			}
		}
		
		/* Enter Y or y to continue, otherwise to quit */
		printf("Do you want to continue? Y/N\n");
		scanf(" %c", &cont);
	}
}
