/* 
   Computer Science 2211B
   Assignment 5
   Yimin Xu
   250876566
   matrix.c
*/

#include "matrix.h"
#include "bs_tree.h"
#include "datatype.h"
#include <stdio.h>

void replace(Matrix m, Key key, Data_Item data);

// Matrix construction using bs_tree_ini()
Matrix matrix_construction(void)
{
	Matrix m = (Matrix) bs_tree_ini();
	return m;
}

//If at location (index1, index2) in Matrix m, the value is defined, then return a pointer to the associated data. Otherwise, return NULL.
Data_Item *matrix_get(Matrix m, Index index1, Index index2)
{
	Key i = key_gen(index1, index2);
	
	return bs_tree_search(m, i);
}

//Assign data to Matrix m at location (index1, index2). If that location already has data, then overwrite.	
void matrix_set(Matrix m, Index index1, Index index2, Data_Item data)
{
	Key i = key_gen(index1, index2);
	if (matrix_get(m, index1, index2) == NULL)
		bs_tree_insert(m, i, data);
	else
		*matrix_get(m, index1, index2) = data;
}

// Print values in the matrix m (with bs_tree_traversal())
void matrix_listing(Matrix m)
{
	bs_tree_traversal(m);
}

// Free allocated space (with bs_tree_free())
void matrix_destruction(Matrix m)
{
	bs_tree_free(m);
}
