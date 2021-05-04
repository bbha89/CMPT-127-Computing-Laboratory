/*
 * imageops.c - Simple operations on images
 *
 * C laboratory exercises.
 * Richard Vaughan, 2014.
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* PAIR SECTION BEGINS - WORK WITH YOUR PARTNER ON THESE TASKS */

/*-------------------------------------------------
  PART 0: DEMONSTRATION
*/


// get the value in the array at coordinate (x,y)
uint8_t get_pixel( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows,
           unsigned int x,
           unsigned int y )
{
    assert( x < cols );
    assert( y < rows );
    return array[ y*cols + x ];
}

// set the pixel at coordinate {x,y} to the specified color
void set_pixel( uint8_t array[], 
        unsigned int cols, 
        unsigned int rows,
        unsigned int x,
        unsigned int y,
        uint8_t color )
{
    assert( x < cols );
    assert( y < rows );
    array[ y * cols + x ] = color;
} 

// Set every pixel to 0 (black) 
void zero( uint8_t array[],
	   unsigned int cols,
	   unsigned int rows )
{
  // your code here.
}

// Returns a pointer to a freshly allocated array that contains the
// same values as the original array, or a null pointer if the
// allocation fails. The caller is responsible for freeing the array
// later.
uint8_t* copy( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows )
{
  // your code here
  return NULL;
}



/*-------------------------------------------------
  PART 1: OPERATIONS ON THE WHOLE IMAGE 
*/

/* TASK 1 - three easy functions to get started */

// Return the darkest color that appears in the array; i.e. the
// smallest value
uint8_t min( const uint8_t array[], 
	     unsigned int cols, 
	     unsigned int rows )
{
  // your code here

int darkest_c= 10000;
for (int i =0; i< cols*rows; i++)
{
  if (array[i] < darkest_c)
  {
    darkest_c = array[i];
  }
}
  return darkest_c;
}

// Return the lightest color that appears in the array; i.e. the
// largest value
uint8_t max( const uint8_t array[], 
		 unsigned int cols, 
		 unsigned int rows )
{
  // your code here

int lightest_c = 0;
for (int j =0; j<cols*rows;j++)
{
  if (array[j] > lightest_c)
  {
    lightest_c = array[j];
  }
}
  return lightest_c;
}

// TASK 2

//  Replace every instance of pre_color with post_color.
void replace_color(  uint8_t array[], 
		     unsigned int cols, 
		     unsigned int rows,
		     uint8_t pre_color,
		     uint8_t post_color )
{
  // your code here

for(int i = 0;i < cols*rows;i++)
{
  if (array[i]== pre_color)
  {
    array[i] = post_color;
  }
}
}
/* TASK 3  - two functions */


// flip the image, left-to-right, like in a mirror.
void flip_horizontal( uint8_t array[], 
              unsigned int cols, 
              unsigned int rows )
{
  // your code here
  int tempperary = 0;
  int j = 0;
  int b = 0;
  for(int i = 0; i < rows;i++){
    for(int j = 0;j <cols/2;j++){
      tempperary = array[j+(i*cols)];
      // Changes the mirror polar opposites of each other
      array[j+(i*cols)] = array[(i*cols)+(cols-j-1)];
      //makes sures it is i*cols to move on to the right
      array[(cols-j-1)+(i*cols)] = tempperary;
      //moves towards the left
    }
  }
}

// flip the image top-to-bottom.
void flip_vertical( uint8_t array[], 
            unsigned int cols, 
            unsigned int rows )
{
  int i = 0;
  int tempperary = 0;
  int j = 0;
  int b = 0;
  for (i=0; i < cols; i++){
      for (j=0; j< rows/2; j++){
      tempperary = array[i+(j*cols)];
      array[i+(j*cols)] = array[(rows-1-j)*cols+i];
      // starts at end, times by cols to make
      //it still start at end and go by column to the right
      array[i+(rows-j-1)*cols] = tempperary;
    }
  }

}

/* TASK 4 */

// Find the first coordinate of the first pixel with a value that
// equals color. Search from left-to-right, top-to-bottom. If it is
// found, store the coordinates in *x and *y and return 1. If it is
// not found, return 0.
int locate_color(  const uint8_t array[], 
		   unsigned int cols, 
		   unsigned int rows,
		   uint8_t color,
		   unsigned int *x,
		   unsigned int *y )
{
    // your code here
    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
        if ((get_pixel(array,cols,rows,j,i)) == color){//call function
            *x = j;
            *y = i;
        return 1;
      }
    }
  }
    return 0;
}



/* TASK 5 */

// Invert the image, so that black becomes white and vice versa, and
// light shades of grey become the corresponding dark shade. 
void invert( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows )
{
    // your code here
  uint8_t darkest= 255;
  uint8_t lightest = 0;
  int grey;
  uint8_t shade = grey;

    for (int r=0; r<rows; r++)
  {
    for (int c=0 ; c<cols; c++)
    {//swap the two intensities black = white, white = black
      uint8_t shade = get_pixel(array, cols, rows, c, r);
      //find the current pixel
      set_pixel(array, cols, rows, c, r, darkest-shade);
      //set to specific color of dark shade.
      //not light grey anymore
    }
  }
}
//forloop through rows*cols
//array[i]=255-array[i];

/* TASK 6 */

// Multiply every pixel by scale_factor, in order to brighten or
// darken the image. Any resulting value over 255 is
// thresholded to 255.
void scale_brightness( uint8_t array[],
            unsigned int cols,
            unsigned int rows,
            double scale_factor )
{
  // your code here
  for (int i=0; i<cols*rows; i++)
  {
    float brightdark = array[i] * scale_factor;//multiply every pixel
    if (255 < brightdark)
      { 
        array[i] = 255;//over 255 is 255
      }
    else
      {
        array[i] = round(brightdark);//else some other value
      }//round cause i'm always off by 1 cause of rounding error...
    }
}


/* TASK 7 */

// Normalize the dynamic range of the image, i.e. Shift and scale the
// pixel colors so that that darkest pixel is 0 and the lightest pixel
// is 255. Hint: you already wrote min() and max(). 
void normalize( uint8_t array[],
        unsigned int cols,
        unsigned int rows )
{
    // your code here
int maxa;//lightest value = max//0
int mina;//darkest = min/255

mina = min(array,cols,rows);//min value
maxa = max(array,cols,rows);//max value

for( int i = 0; i <cols*rows;i++)//uint8_t makes the max 255 so 256 is 0.
{//using the normalizatin method, the range increases, it stretches.

  array[i] = round((255.000*(array[i]-mina))/(maxa-mina));
  //normalization formula xnew = (x-xmin)/(xmax-xmin)
  // array[i] = round(newarr);//xnew value && rounding
  }
}

/* TASK 8 */

// Return a new image of size rows/2 by cols/2 If the original image              
// has an odd number of columns, ignore its rightmost column. If the              
// original image has an odd number of rows, ignore its bottom row.               
// The value of a pixel at (p,q) in the new image is the average of               
// the four pixels at (2p,2q), (2p+1,2q), (2p+1,2q+1), (2p,2q+1) in               
// the original image.                                                            
uint8_t* half( const uint8_t array[],
	       unsigned int cols,
	       unsigned int rows )
{
  // your code here
if(cols%2 == 0)
{;}
else
{cols--;}//remove rightmost column
if(rows%2 == 0)
{;}
else
{rows--;}//remove last row
//new image of half size
  uint8_t *halfimage = malloc(cols/2*rows/2*sizeof(uint8_t));
  if(halfimage == NULL || cols == 0 || rows == 0)
  {
    return NULL;
  }
float average = 0.0;
float average2 = 0.0;
float average3 = 0.0;
float average4 = 0.0;
float total = 0.0;
float img_value = 0.0;
if(halfimage == 0 || rows ==0 || cols == 0)
{
  return NULL;
}
int i,j;
for (i = 0; i < cols; i+=2)
{
  for (j = 0; j < rows ; j+=2)
  {  
    average = get_pixel(array,cols,rows,i,j);
    average2  = get_pixel(array,cols,rows,i,j+1);
    average3 = get_pixel(array,cols,rows,i+1,j);
    average4 = get_pixel(array,cols,rows,i+1,j+1);
    total = round((average+average2+average3+average4)/4.000);
    set_pixel(halfimage,cols/2,rows/2,i/2,j/2,total);
  }
}
return halfimage;
}
/*-------------------------------------------------
  PART 2: OPERATIONS ON IMAGE SUB-REGIONS

  These functions operate only on a rectangular region of the array
  defined by a (left,top) corner (i.e. closer to the image origin) and
  (right,bottom) corner (i.e. further from the image origin).

  The region includes all the columns from [left, right-1] inclusive,
  and allthe rows from [top, bottom-1] inclusive.
  
  In every case, you may assume that left <= right and top <= bottom:
  do not need to test for this.

  The area of the region is right-left * bottom-top pixels, which
  implies that if left == right or top == bottom, the region has no
  area and is defined as "empty". Each function notes how to handle
  empty regions.
 
  In every function, use assert() to test bounds on the region
  corners.
*/

/* TASK 9 */

// Set every pixel in the region to color. If the region is empty, the
// image must be unchanged.
void region_set( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows,
         unsigned int left,
         unsigned int top,
         unsigned int right,
         unsigned int bottom,
         uint8_t color )
{
int xrows = 0;
int ycols = 0;
    // your code here
if((left != right)&&(top!=bottom))
{
	for(xrows = left; xrows < right; xrows++)
	{
		for(ycols = top; ycols < bottom; ycols++)
		{
			set_pixel(array, cols, rows, xrows, ycols, color);//set pixel to certain color
		}
	}
}
}

/* TASK 10 */

// Return the sum of all the pixels in the region. Notice the large
// return type to handle potentially large numbers. Empty regions
// return the sum 0.
unsigned long int region_integrate( const uint8_t array[], 
                    unsigned int cols, 
                    unsigned int rows,
                    unsigned int left,
                    unsigned int top,
                    unsigned int right,
                    unsigned int bottom )
{
    // your code here
    return 0;
}

/* TASK 11 */

// Get a new image which is a copy of the region. Empty regions return
// a null pointer. If memory allocation fails, return a null
// pointer. The caller is responsible for freeing the returned array
// later.
uint8_t* region_copy( const uint8_t array[], 
              unsigned int cols, 
              unsigned int rows,
              unsigned int left,
              unsigned int top,
              unsigned int right,
              unsigned int bottom )
{
    // your code here
  int row = right-left;
  int temp;
  intptr_t* img = malloc(sizeof(int)*(bottom-top)*row);
  //create space for new image which is the copy of whole region
if(top != bottom && right != left)
{
  for(int i = left;i<=right-1;i++)//goes through the matrix
  {
    for(int j = top;j<bottom;j++)
    {
        temp = get_pixel(array,cols,rows,i,j);
        set_pixel(img,(row),(bottom - top)//set and get function operated
        ,i-left, j-top, temp);
        if(img == NULL)
        {
          return NULL;
        }
    }
  }
return img;
}
if(img == NULL)
{
return NULL;
}
return NULL;
}

// int main()
// {
//   unsigned int cols = 5;
//   unsigned int rows = 4;
//   unsigned int left = 2;
//   unsigned int right = 4;
//   unsigned int top = 0;
//   unsigned int bottom = 3;
//   unsigned int color = 35;

//   uint8_t array[20]= {0,1,2,3,4,
//           5,6,7,8,9,
//           10,11,12,13,14,
//           15,16,17,18,19};

// uint8_t*new = half(array,cols,rows);
// for (int i =0; i<20;i++)
//   printf("%d\n",new[i]);

// return 0;
// }