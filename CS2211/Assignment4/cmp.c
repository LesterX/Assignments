#include <stdio.h>
#include <string.h>

int main()
{
	char * toinsert[10] = {"Once", "Upon", "a", "Time", "is", "filmed", "in", "Vancouver", "!"};
	int i,j;
	for (i = 0; i < 9; i ++)
	{
		for (j = 0; j < 9; j ++)
		{
			if (strcmp(toinsert[i],toinsert[j]) < 0)
			{
				char * change = toinsert[i];
				toinsert[i] = toinsert[j];
				toinsert[j] = change;
			}
		}
	}

	int k;
	for (k = 0; k < 9; k ++)
		printf("%s\n", toinsert[k]);

	char * a = "a";
	char * b = "Vancouver";
	int p = strcmp(a, b);
	if (p > 0)
		printf("%c is before %c\n", *b, *a);
	else if (p < 0)
		printf("%c is before %c\n", *a, *b);
}
