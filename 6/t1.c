#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intarr.h"

/* LAB 6 TASK 1 */

/*
  Save the entire array ia into a file called 'filename' in a binary
  file format that can be loaded by intarr_load_binary(). Returns
  zero on success, or a non-zero error code on failure. Arrays of
  length 0 should produce an output file containing an empty array.
*/

int intarr_save_binary( intarr_t* ia, const char* filename )
{
  //*fopen - open a stream*//
//**The fopen() function shall open the file whose pathname is the 
//string pointed to by filename, and associates a stream with it.**
//FILE *fopen(const char *restrict filename, const char *restrict mode);
  if (ia == NULL)//nothing to save, failed
  {
    return 1;
  }
  if(filename == NULL)
  {
  	return 1;
  }
  FILE *f_open = fopen(filename,"w");
  
  int hdr[1];
  hdr[0] = ia->len;

  if(fwrite(hdr,sizeof(int),1,f_open) != 1)
  	return 1;

  if(f_open == NULL)
  {
  	return 1;
  }

  if(fwrite(ia->data,sizeof(int),ia->len,f_open) != ia->len)
  {
  	return 1;
  }
  else
  {
    fclose(f_open);
    return 0;
  }
fclose(f_open);
return 1;    
}

//int fclose(FILE *stream);//associated file to close//success = return 0 else EOF(error)

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save_binary(). Returns a pointer to a
  newly-allocated intarr_t on success, or NULL on failure.
*/
intarr_t* intarr_load_binary( const char* filename )
{

  
  FILE *f_open = fopen(filename,"r");

  if(filename == NULL)
  {
    return NULL;
  } 
  if(f_open == NULL)
  {
    return NULL;
  }

  int hdr[1];
  fread(hdr,sizeof(int),1,f_open);
  int len = hdr[0];



intarr_t * new = intarr_create(len);//use existing function(save time don't need to malloc for space)
  new->len = len;
fread(new->data,sizeof(int),len,f_open) != len;

return new;//newly-allocated intarr_t on success
}