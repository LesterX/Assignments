/* Computer Science 2211B
   Section 001
   Assignment 4
   Yimin Xu
   250876566 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

void insert_help(int i, BStree bst, Node n);
void inorder_help(int i, BStree bst);

// Input: ’size’: size of an array
// Output: a pointer of type BStree,
//         i.e. a pointer to an allocated memory of BStree_struct type 
// Effect: dynamically allocate memory of type BStree_struct
//         allocate memory for a Node array of size+1 for member tree_nodes
//         allocate memory for an unsigned char array of size+1 for member is_free
//         set all entries of is_free to 1
//         set member size to ’size’;
BStree bstree_ini(int size) 
{
	BStree tree = (BStree) malloc(sizeof (BStree_struct));
	Node * nodes = (Node *) malloc((size + 1) * sizeof(Node));
	unsigned char * isfree = (unsigned char *) malloc((size + 1) * sizeof(unsigned char));
	int i = 0;
	
	for (i = 0; i < size + 1; i ++)
		isfree[i] = 1;		
	
	tree->size = size;
	tree->tree_nodes = nodes;
	tree->is_free = isfree;

	return tree;
}

// Input: ’bst’: a binary search tree
//        ’key’: a string
//        ’data’: an integer
// Effect: ’data’ with ’key’ is inserted into ’bst’
//         if ’key’ is already in ’bst’, do nothing
void bstree_insert(BStree bst, char *key, int data) 
{
	Node n;
	n.key = key;
	n.data = data;
	int i = 1;
	insert_help(i, bst, n);	
}

//  Input:  array index i
//			Binary search tree bst
//			node n to be inserted
//	Effect: recursively finding the proper position
//			to insert the node
void insert_help(int i, BStree bst, Node n)
{
	if (i >= (*bst).size)
	{
		printf("Out of range.\n");
		return;
	}

	if ((*bst).is_free[i])
	{
		(*bst).tree_nodes[i] = n;
		(*bst).is_free[i] = 0;
	}else if (strcmp((*bst).tree_nodes[i].key, n.key) > 0)
		insert_help(2 * i, bst, n);
	else if (strcmp((*bst).tree_nodes[i].key, n.key) < 0)
		insert_help(2 * i + 1, bst, n);
}

// Input: ’bst’: a binary search tree
// Effect: print all the nodes in bst using in order traversal
void bstree_traversal(BStree bst) 
{
	int i = 1;
	inorder_help(i, bst);
}

// Input: array index i
//		  BStree to traverse bst
// Output: Recursively print out the key and data in 
//		   the nodes, from the smallest to the largest
void inorder_help(int i, BStree bst)
{
	if (i >= (*bst).size || bst->is_free[i] == 1)
	{
		return;
	}

	inorder_help(2 * i, bst);
	printf("%-10s				%-2d\n", (*bst).tree_nodes[i].key, (*bst).tree_nodes[i].data);
	inorder_help(2 * i + 1, bst);
}

// Input: ’bst’: a binary search tree
// Effect: all memory used by bst are freed
void bstree_free(BStree bst) 
{
	free(bst->tree_nodes);
	free(bst->is_free);
	free(bst);
}

