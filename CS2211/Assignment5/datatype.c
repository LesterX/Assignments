/* 
   Computer Science 2211B
   Assignment 5
   Yimin Xu
   250876566
   datatype.c
*/

#include "datatype.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Use strcmp( ) to do comparison. If key1.key1 and key2.key1 are different, then they de- termine the comparison result. If key1.key1 and key2.key1 are the same, then key1.key2 and key2.key2 determine the comparison result.
int key_comp(Key k1, Key k2)
{
	Key *pk1 = &k1, *pk2 = &k2;

	if (pk1 == NULL && pk2 == NULL)
		return 0;
	else if (pk1 == NULL)
		return -1;
	else if (pk2 == NULL)
		return 1;

	if (strcmp(k1.key1, k2.key1) != 0)
		return strcmp(k1.key1, k2.key1);
	else return strcmp(k1.key2, k2.key2);
}

// Allocate memory and return the subkey
Sub_Key sub_key_dup(Sub_Key skey)
{
	char *dup = (char *) malloc(strlen(skey) + 1);
	dup = strcpy(dup, skey);

	return dup;
}

// Use the two subkeys to build a Key
Key key_gen(Sub_Key key1, Sub_Key key2)
{
	Key k;
	k.key1 = sub_key_dup(key1);
	k.key2 = sub_key_dup(key2);
	return k;
}

// Print the two subkeys in the key
void key_print(Key key)
{
	printf("%10s    %10s      ", key.key1, key.key2);
}

// Print the data
void data_print(Data_Item data)
{
	int d = (int) data;
	printf("%10d\n", d);
}
