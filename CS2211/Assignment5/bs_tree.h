/* 
   Computer Science 2211B
   Assignment 5
   Yimin Xu
   250876566
   bs_tree.h
*/

#ifndef BStree_node_H
#define BStree_node_H

	#include "datatype.h"
	
	struct BStree_node 
	{
		Key key;
		Data_Item data;
		struct BStree_node *left, *right;
	};
	typedef struct BStree_node BStree_node;
	typedef BStree_node** BStree;

	// Allocate memory of type BStree node*, set the value to NULL, and return a pointer to the allocated memory.
	BStree bs_tree_ini(void);
	
	// Insert data with key into bst. If key is in bst, then do nothing.
	void bs_tree_insert(BStree bst, Key key, Data_Item data);
	
	// Helper function for insertion to create a pointer to a tree node from key and data.
	BStree_node *new_node(Key key, Data_Item data);
	
	// If key is in bst, return a pointer to key’s associated data. If key is not in bst, return NULL.
	Data_Item *bs_tree_search(BStree bst, Key key);
	
	// In order traversal of bst and print each node’s key and data.
	void bs_tree_traversal(BStree bst);
	
	// Free all the dynamically allocated memory of bst.
	void bs_tree_free(BStree bst);
	
#endif
