#include <stdlib.h>
#include <stdio.h>
int identical( int a[], int b[], unsigned int len){
int answer = 0;

    if (len == 0)
{
	return 1;
}

for (int i = 0; i < len; i++)
{

	if(a[i] != b[i])
      {
      	return 0;
      }
	else
	{
		answer = 1;
	}

}
return answer;
}  
/*	
int main( void )
{
  int a[3] = {10, 20, 15};
  int b[3] = {10, 20, 15};
 
  if( identical( a, b, 3 ) == 1 )
  {
     printf( "a and b are identical\n" );
  } else {
    printf( "a and b are NOT identical\n" );
  }
  
  return 0;
}
*/