/* Computer Science 2211B
   Section 001
   Assignment 4
   Yimin Xu
   250876566 */

#include <stdio.h>
#include <string.h>
#include "data.h"

// Input: ’node’: a node
// Effect: node.key is printed and then the node.data is printed
void print_node(Node node) 
{
	printf("%s %d\n", node.key, node.data);
}

// Input: ’key’: a string ends with ’\0’
// Output: a pointer of type pointer to char,
//         pointing to an allocated memory containing a copy of ’key’
// Effect: dynamically allocate memory to hold a copy of ’key’
char *key_dup(char *key) 
{
	char *k;
	k = strdup(key);
	return k;
}
