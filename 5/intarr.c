#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intarr.h"

/* LAB 5 TASK 1 */

// Create a new intarr_t with initial size len.  If successful
// (i.e. memory allocation succeeds), returns a pointer to a
// newly-allocated intarr_t.  If unsuccessful, returns a null pointer.
intarr_t* intarr_create( unsigned int len )
{ 
	
	
intarr_t* old=NULL;
old=malloc(sizeof(intarr_t));
if(old!=NULL)
{
	(*old).data=malloc(len*sizeof(int));//create space.
	(*old).len = len;//initial size len
	return old;//in main would return new pointer
}
else if(old==NULL)//not succeed would be null
{
	free(old);
	return NULL;
}
return NULL;
}
// frees all memory allocated for ia. If the pointer is null, do
// nothing. If the ia->data is null, do not attempt to free it.
void intarr_destroy( intarr_t* ia )
{
if (ia->data == NULL)
	{;}//Do nothing.
else if(ia->data != NULL)//free if not equal to Null
	{free(ia);}
}
/* LAB 5 TASK 2 */

// If index is valid, set the value at ia->data[index] to val and return
// INTARR_OK. Otherwise, leave the array unmodified and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_set( intarr_t* ia, 
			    unsigned int index, 
			    int val )
{
if(ia == NULL)
	{return INTARR_BADARRAY;}

else if(index<0 ||index > (*ia).len)
{return INTARR_BADINDEX;}
else if(index>=0)
{
	ia->data[index]=val;
	return INTARR_OK;
}
return 0;
}
// If index is valid and i is non-null, set *i to ia->data[index] and return
// INTARR_OK. Otherwise no not modify *i and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_get( const intarr_t* ia, 
			    unsigned int index, 
			    int* i )
{

	if(ia==NULL)
	{
		return INTARR_BADARRAY;//if ia is NULL
	}
	else if( (index <0)|| (i==NULL) || index > ia->len)
	{
		return INTARR_BADINDEX;//not modify *i
	}
	else
	{
		*i = (*ia).data[index];//set *i to ia->data[index]
		return INTARR_OK;
	}
	return 0;
}

/* LAB 5 TASK 3 */

// Return a duplicate of ia, allocating new storage for the duplicate
// data (we call this a "deep copy"). If unsuccessful (i.e. memory
// allocation for the copy fails, or ia is null), return a null pointer. 
intarr_t* intarr_copy( const intarr_t* ia )
{
	intarr_t* duplicate = NULL;

	if (ia!= NULL)
	{
	duplicate = malloc(sizeof(intarr_t));//make space

	int numbytes = (ia->len*sizeof(int));//not *intarr_t
	duplicate->data = malloc(numbytes);//make new data array
		//can't copy ia->data because it will change both when something changes
	duplicate->len = ia->len;//make duplicate same length as ia
		//(this doesn't affect the data)
	memcpy(duplicate->data, ia->data,numbytes);//make data from ia into duplicate
	return duplicate;//return the new data
	}
	else if(ia == NULL)
	{
		return NULL;//if storage is NULL
	}
}

/* LAB 5 TASK 4 */

// sort ia by value smallest-to-largest, so that data[i] < data[i+1]
// for all valid i, then return INTARR_OK. Works in-place: contents of
// ia are sorted on return. If ia is null, return
// INTARR_BADARRAY.
intarr_result_t intarr_sort( intarr_t* ia ){

int index = 0;
if(ia == NULL)
{
	return INTARR_BADARRAY;
}
else if (ia!= NULL)
{
	for(int i = 0; i<=(ia->len);i++)//keeps checking until the data length has been sorted
	{
		index = i;//the current index
		int min = ia->data[i];//create data space
		for(int j = i+1; j<(ia->len);j++){//i+1 b/c we want the length compared to be smaller each time
			//so that we don't check the ones that are already sorted
			int min_2 = ia->data[j];//create data space
			if(min_2 < min)//comparing two 'elements' to see which is smaller
			{
				min = min_2;
				index = j;//if min is less than, change the index to this
			}
		}
		printf("%d this is the value of j\n", index);
		int temp;//temp variable used similarly when dealing with swap
		temp = ia->data[i];//can't used variable 'min' because won't actually change the ia->data
		ia->data[i] = ia->data[index];
		ia->data[index]= temp;//ensures the data is not the same originally if min has changed
	}
	return INTARR_OK;
}

}
//**125 notes**
/*int partition(int arr[], int first, int last) {
 int mid = first;
 int pivot = arr[first];
 for (int sweep = first+1; sweep <= last; sweep++) {
 // Assertion: . . .
 if (arr[sweep] < pivot) {
 int tmp = arr[sweep];
 arr[sweep] = arr[mid+1];
 arr[mid+1] = tmp;
 mid++;
 }
 }
 // Post: . . .
 arr[first] = arr[mid];
 arr[mid] = pivot;
 return mid;
}
*/
/* LAB 5 TASK 5 */

// Find the first occurance of the target in the array, searching from
// index 0. If the target is found and i is non-null, set *i to the
// location index and return INTARR_OK. If target does not occur in
// the array, leave *i unmodified and return INTARR_NOTFOUND. If ia is
// null, return INTARR_BADARRAY.
intarr_result_t intarr_find( intarr_t* ia, int target, int* i )
{
if(ia!=NULL)
{
	for(int b = 0;b<ia->len;b++)
	{
		int find = ia->data[b];
		if(find == target)
		{
			*i = b;
			return INTARR_OK;
		}
	}
	return INTARR_NOTFOUND;
}
else if (ia==NULL)
{
	return INTARR_BADARRAY;
}


}
/* LAB 5 TASK 6 */

// Append val to the end of ia (allocating space for it). If
// successful, return INTARR_OK, otherwise return
// INTARR_BADALLOC. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_push( intarr_t* ia, int val )
{

if (ia != NULL)
{
	ia->len = ia->len+1;//append length
	realloc(ia->data,(ia->len)*sizeof(int));//resizing malloc
	ia->data[ia->len-1] = val;//make length bounded
	return INTARR_OK;
}
else if(ia == NULL)
	{return INTARR_BADARRAY;}
return INTARR_BADALLOC;
}
// If the array is not empty, remove the value with the highest index
// from the array, and, if i is non-null, set *i to the removed value,
// then return INTARR_OK. If the array is empty, leave *i unmodified
// and return INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_pop( intarr_t* ia, int* i )
{
	if (ia == NULL)
	{
		return INTARR_BADARRAY;
	}
	if(ia->data !=NULL)//not empty
	{
		if(ia->len!=0){
		ia->len = ia->len-1;//remove the value w/ the highest index
		*i = ia->data[ia->len];
		//removes the last index from the array if not NULL.
		//set *i to the removed value
		return INTARR_OK;
		}
		else{
		return INTARR_BADINDEX;//any cases where len is 0 and the data is none.
		}
	}
}

/* LAB 5 TASK 7 */

// Resize ia to contain newlen values. If newlen is less than the
// original array length, the end of the array is discarded. If newlen
// is greater than the original array length, intialize all the new
// integers to zero. If the allocation is successful, return
// INTARR_OK, otherwise return INTARR_BADALLOC. If ia is null, return
// INTARR_BADARRAY.
intarr_result_t intarr_resize( intarr_t* ia, unsigned int newlen )
{
intarr_t* length = NULL;
intarr_t* new = NULL;
length = ia->len;
if(newlen > ia->len)//if the new length is greater than current array length
{
	int  i = length;//the old length
	while(i < newlen)//the added length
	{
		ia->data[i] = 0;//set every integer to zero
	i++;
	}
	ia->len = newlen;
	return INTARR_OK;
}
else if(newlen <= length)
{
	ia->len = newlen;//gets rid of the current length and keeps the new one
	return INTARR_OK;
}
else if (ia==NULL)
{
	return INTARR_BADARRAY;
}
return INTARR_BADALLOC;



	
}

/* LAB 5 TASK 8 */

// Get a deep copy of a portion of ia from index first to index last
// inclusive. If successful, return a pointer to a newly-allocated
// intarr_t containing a copy of the specfied section. If an error
// occurs, i.e. ia is null, first or last are out of bounds, last <
// first, or memory allocation fails, return a null pointer.
intarr_t* intarr_copy_subarray( intarr_t* ia, 
				unsigned int first, 
				unsigned int last )
{
	
intarr_t * duplicate = NULL;
int i = 0;
int k = 0;
if(last < first)
{
	return NULL;
}
if(ia == NULL)
{
	return NULL;
}
if(0>first)
{
	return NULL;
}
duplicate = malloc(sizeof(int));//create space for new variable
duplicate->len = last-first+1;//inclusive first to last
int length = last-first+1;
	duplicate->data = malloc(sizeof(int)*(length));	
	i = first;
	while(i<=last)
	{
		duplicate->data[k] = ia->data[i];//copy
	i++;
	k++;
	}
return duplicate;//return the deep copy
}
/* -------------------------------------------------------------- */

/* LAB 6 TASK 1 */

/*
  Save the entire array ia into a file called 'filename' in a binary
  file format that can be loaded by intarr_load_binary(). Returns
  zero on success, or a non-zero error code on failure. Arrays of
  length 0 should produce an output file containing an empty array.
*/
int intarr_save_binary( intarr_t* ia, const char* filename )
{int yo = 23;}

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save_binary(). Returns a pointer to a
  newly-allocated intarr_t on success, or NULL on failure.
*/
intarr_t* intarr_load_binary( const char* filename )
{int yo = 23;}


/* LAB 6 TASK 2 */

/*
  Save the entire array ia into a file called 'filename' in a JSON
  text file array file format that can be loaded by
  intarr_load_json(). Returns zero on success, or a non-zero error
  code on failure. Arrays of length 0 should produce an output file
  containing an empty array.
  
  The JSON output should be human-readable.

  Examples:

  The following line is a valid JSON array:
  [ 100, 200, 300 ]
  
  The following lines are a valid JSON array:
  [ 
   100, 
   200, 
   300 
  ]
*/
int intarr_save_json( intarr_t* ia, const char* filename ){int yo = 23;}

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save(). The file may contain an array
  of length 0. Returns a pointer to a newly-allocated intarr_t on
  success (even if that array has length 0), or NULL on failure.
*/
intarr_t* intarr_load_json( const char* filename )
{int yo = 23;}