/* 
   Computer Science 2211B
   Assignment 5
   Yimin Xu
   250876566
   main.c
*/

#include "matrix.h"
#include <stdio.h>
#include <string.h>


int main()
{
	// Initialize the matrix
	Matrix m = matrix_construction();

	// Initialize the character pointers
	char str1[100], str2[100], name[20], line[100], *pch;

	// Open the file that contains the keys
	// My file is called 'keys.txt'
	// Also I didn't allocate too much size for the strings
	// So if you are using your own file 
	// please please please please please
	// don't put too many spaces between the strings 
	// or it will not look very clean
	puts("Enter the name of the file that contains keys");
	scanf("%s", name);
	FILE *file = fopen(name, "r");


	while (fgets(line, sizeof(line), file))
	{	
		// When the line is empty, end the loop
		if (strlen(line) == 0)
			break;

		// Split the line with whitespace the newline
		pch = strtok(line, " \n");

		// str1 is the first token and str2 is the next
		strcpy(str1, pch);

		pch = strtok(NULL, " \n");

		// If str2 is empty, there is only one subkey, end the loop
		if (pch == NULL)
			break;

		strcpy(str2, pch);

		// If this key is new, insert it to the matrix
		// Else add 1 to the data in [str1, str2]
		if (matrix_get(m, str1, str2) == NULL)
			matrix_set(m, str1, str2, 1);
		else
			matrix_set(m, str1, str2, *matrix_get(m, str1, str2) + 1);
	}

	// Print the result
	puts("     String 1      String 2        Occurence");
	matrix_listing(m);
	matrix_destruction(m);
} 






// Thank you for reading...... ( wait , you really read the code??? )
