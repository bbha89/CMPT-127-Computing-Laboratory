    #include <stdio.h>
     
    // declaration of function implemented in reverse.c
    void reverse( int arr[], unsigned int len );
     
    int main( void )
    {
      int a[] = {11, 12, 13};
      unsigned int len = 3;
     
      reverse( a, len );
     
      int i=0;
      for( i=0; i<len; i++ )
      {   
         printf( "%d ", a[i] );
      }
      printf( "\n" ); 
     
      return 0;
    }