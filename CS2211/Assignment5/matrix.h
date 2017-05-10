/* 
   Computer Science 2211B
   Assignment 5
   Yimin Xu
   250876566
   matrix.h
*/

#ifndef matrix_H
#define matrix_H
	#include "bs_tree.h"
	typedef BStree Matrix;
	typedef Sub_Key Index;

	//Matrix construction using bs tree ini();	
	Matrix matrix_construction(void);
	
	//If at location (index1, index2) in Matrix m, the value is defined, then return a pointer to the associated data. Otherwise, return NULL.
	Data_Item *matrix_get(Matrix m, Index index1, Index index2);
	
	//Assign data to Matrix m at location (index1, index2). If that location already has data, then overwrite.	
	void matrix_set(Matrix m, Index index1, Index index2, Data_Item data);
	
	//Print values in the Matrix m (with bs tree traversal()). 	
	void matrix_listing(Matrix m);
	
	//Free allocated space (with bs tree free()).
	void matrix_destruction(Matrix m);
	
#endif
