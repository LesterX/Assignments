/* 
   Computer Science 2211B
   Assignment 5
   Yimin Xu
   250876566
   bs_tree.c 
*/

#include "bs_tree.h"
#include "datatype.h"
#include <stdlib.h>
#include <stdio.h>

// Allocate memory of type BStree node*, set the value to NULL, and return a pointer to the allocated memory.
BStree bs_tree_ini(void)
{
	BStree bst;
	bst = (BStree) malloc(sizeof(BStree_node*)); 
	*bst = NULL;
	return bst;
}

// Insert data with key into bst. If key is in bst, then do nothing.
void bs_tree_insert(BStree bst, Key key, Data_Item data)
{
	BStree_node * target = new_node(key,data);
	if (*bst == NULL)
	{
		*bst = target;	
		return;
	}

	BStree_node root = **bst;
	if (key_comp(root.key, key) < 0)
	{
		if (root.right == NULL)
			(**bst).right = target; 
		else
			bs_tree_insert(&root.right, key, data);
	}
	else if (key_comp(root.key, key) > 0)
	{
		if (root.left == NULL)
			(**bst).left = target;
		else
			bs_tree_insert(&root.left, key, data);			
	}
}

// Helper function for insertion to create a pointer to a tree node from key and data.
BStree_node *new_node(Key key, Data_Item data)
{
	BStree_node *node = (BStree_node *) malloc(sizeof(BStree_node));
	(*node).key = key;
	(*node).data = data;
	(*node).left = NULL;
	(*node).right = NULL;
	return node;
}

// If key is in bst, return a pointer to key’s associated data. If key is not in bst, return NULL.
Data_Item *bs_tree_search(BStree bst, Key key)
{
	if (*bst == NULL)
		return NULL;

	BStree_node root = **bst;	
	if (key_comp(root.key, key) == 0)
	{
		return &(*bst)->data;
	}
	if (key_comp(root.key, key) < 0)
	{
		if (root.right == NULL)
			return NULL;
		else
			return bs_tree_search(&root.right, key);
	}
	else
	{
		if (root.left == NULL)
			return NULL;
		else	
			return bs_tree_search(&root.left, key);
	}
}

// In order traversal of bst and print each node’s key and data.
void bs_tree_traversal(BStree bst)
{
	if (*bst == NULL)
		return;

	BStree_node root = **bst;		
	if (root.left != NULL)
		bs_tree_traversal(&root.left);
	key_print(root.key);
	data_print(root.data);
	if (root.right != NULL)	
		bs_tree_traversal(&root.right);
}

// Free all the dynamically allocated memory of bst.
void bs_tree_free(BStree bst) 
{
	if (*bst == NULL)
		return;
	
	bs_tree_free(&(**bst).left);	
	bs_tree_free(&(**bst).right);
	free(*bst);
}


