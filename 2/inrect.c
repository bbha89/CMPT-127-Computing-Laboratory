#include <stdio.h>
#include <stdlib.h>

int InRectangle( float pt[2], float rect[4] )
{
float temp = 0;
int i =0;
int j = 0;
//for(i = 0; i <)
//Opposite corner of the rectangle
float x_rect2 = rect[2];
float y_rect2 = rect[3];
//rectangle on the same plane
//x,y coordinates of one corner of the rectangle
float x_rect1 = rect[0];
float y_rect1 = rect[1];
//x & y coordinates of point on the plane
float x_cdn = pt[0];
float y_cdn = pt[1];

if(x_cdn >= x_rect1 && y_cdn >= y_rect1 //topleft
&& x_cdn <= x_rect1 && y_cdn <= y_rect2 //topright
&& x_cdn >= x_rect2 && y_cdn >= y_rect1 //bottomleft
&& x_cdn <= x_rect2 && y_cdn <= y_rect2)//bottomright
	//normal pattern else;
{
	return 1;
}
if (y_rect2 < y_rect1)
//sees if the pattern
// is switched with one another
//makes sure whatever value it is,
//it will be the normal pattern.
{
	temp = y_rect1;
	y_rect1 = y_rect2;
	y_rect2 = temp;
}
if (x_rect2 < x_rect1)
//sees if the pattern
// is switched with one another
{
	temp = x_rect1;
	x_rect1 = x_rect2;
	x_rect2 = temp;
}
if(x_cdn >= x_rect1 && x_cdn <= x_rect2 &&
y_cdn >= y_rect1 && y_cdn <= y_rect2)
{
  return 1;
}
//if it doesn't result in normal pattern 
//then it is outside the rectangle.
return 0;

}
// declaration of function to test
 
// int main( int argc, char* argv[] )
// {
//   // define a rectangle from (1,1) to (2,2)
//   float rect[4] = {-97.39,-21.768253,73.14,-96.99};
 
//   // define a point that is inside the rectangle

//   float poin[2] = {-74.07,-88.068794};

//   float p_in[2] = { 1.5, 1.5 };

//   // define a point that is outside the rectangle
//   float p_out[2] = {2.5, 0.5};
 
//   // define a point that is on the edge of the rectangle
//   float p_edge[2] = {1.0, 1.0};
 
//   // InRectangle() should return 0 (false) for points that are NOT in
//   // the rectangle, and non-zero (true) for points that are in the
//   // rectangle. Points on the edge are considered *in* the rectangle.
 
//   // test 1
//   if( InRectangle( p_in, rect ) == 0 )
//   {
//     puts( "error: should return true for p_in." );
//     return 1; // indicate error
//   }
 
//   // test 2
//   if( InRectangle( p_out, rect ) != 0 )
//   {
//     puts( "error: should return false for p_out." );
//     return 1; // indicate error
//   }
 
//   // test 3
//   if( InRectangle( p_edge, rect ) == 0 )
//   {
//     puts( "error: should return true for p_edge." );
//     return 1; // indicate error
//   }
//   printf("alltestpassed\n");
//   return 0; // all tests passed
// }
