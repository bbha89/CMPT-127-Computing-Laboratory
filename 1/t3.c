#include <stdio.h>
#include <math.h>

int main(void)
{
  float i = 0.0;
  scanf( "%f", &i );
  printf("%.0lf ", floor(i));
  printf("%.0lf ", round(i));
  printf("%.0lf\n", ceil(i));
  return 0;
}
