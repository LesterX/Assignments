/* 
   Computer Science 2211B
   Assignment 5
   Yimin Xu
   250876566
   datatype.h
*/

#ifndef keydata_H
#define keydata_H
	typedef int Data_Item;
	typedef char* Sub_Key;
	typedef struct {Sub_Key key1; Sub_Key key2;} Key;

	// Use strcmp( ) to do comparison. If key1.key1 and key2.key1 are different, then they de- termine the comparison result. If key1.key1 and key2.key1 are the same, then key1.key2 and key2.key2 determine the comparison result.
	int key_comp(Key k1, Key k2);

	// Allocate memory and return the subkey
	Sub_Key sub_key_dup(Sub_Key skey);

	// Use the two subkeys to build a Key
	Key key_gen(Sub_Key key1, Sub_Key key2);

	// Print the two subkeys in the key
	void key_print(Key key);

	// Print the data
	void data_print(Data_Item data);

#endif
