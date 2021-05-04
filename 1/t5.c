#include <stdio.h>
#include <math.h>

int main(void)
{
float i = 0;

int n = scanf( "%f", &i );
while (n != EOF)
{

  printf("%.0lf ", floor(i));
  printf("%.0lf ", round(i));
  printf("%.0lf\n", ceil(i));
 n = scanf( "%f", &i );
}
 printf("Done.\n");
 return 0;
}
