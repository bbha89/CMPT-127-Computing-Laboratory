#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intarr.h"
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
int intarr_save_json( intarr_t* ia, const char* filename )
{
  {
  int i = 0;

  if (ia == NULL || filename == NULL || ia->data == NULL)
  {
    return 1;
  }
  FILE* f_open = fopen(filename,"w");
  if (f_open == NULL)
  {
    return 1;
  }
  if (ia->len ==0)
  {
    fprintf(f_open,"[\n");
    fprintf(f_open,"]");
    fclose(f_open);
    return 0;
  }
if(filename == NULL)
{
	return 1;
}
  fprintf(f_open,"[\n");
  for (i = 0; i < ia->len; i++)
    {
    	if(i!=ia->len-1)
    	{
    		fprintf(f_open," %d",ia->data[i]);
          	fprintf(f_open,",\n");  		
    	}
    	else
    	{
    		fprintf(f_open," %d\n",ia->data[i]);		
    	}
    }
 if(ia->data == NULL)
 {
 	return 1;
 }
  fprintf(f_open,"]");
  fclose(f_open);
  return 0;
}
}

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save(). The file may contain an array
  of length 0. Returns a pointer to a newly-allocated intarr_t on
  success (even if that array has length 0), or NULL on failure.
*/
intarr_t* intarr_load_json( const char* filename )
{
	int len = 0;
	if(filename == NULL)
	{
		return NULL;
	}
  FILE *f_open = fopen(filename,"r");
  if(f_open == NULL)
  {
  	return NULL;
  }
int arr;
intarr_t * array = intarr_create(len);
if(fscanf(f_open,"[\n %d,\n",&arr) ==0)
  return array;

intarr_push(array,arr);
while(fscanf(f_open," %d,\n",&arr))
{
  intarr_push(array,arr);
}
// fscanf(f_open, " %d\n", &arr);
// intarr_push(array,arr);


fclose(f_open);
return array;
}

