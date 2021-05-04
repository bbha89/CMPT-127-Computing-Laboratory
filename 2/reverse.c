#include <stdio.h>
// declaration of function implemented in reverse.c
void reverse(int arr[], unsigned int len)
{
int temp = 0;
for(int i = 0; i<len/2; i++)
{
  int b = len -i -1;
	temp = arr[i];
	arr[i] = arr[b];
	arr[b] = temp;


	printf("%d %d %d\n", temp,arr[i],arr[b]);
}
return;
}
/*
int main( void )
{
  int a[] = {11, 12, 13, 14, 17};
  unsigned int len = 5;
 
  reverse( a, len );
 
  int i=0;
  for( i=0; i<len; i++ )
  {   
     printf( "%d ", a[i] );
  }
  printf( "\n" ); 
 
  return 0;
}
*/