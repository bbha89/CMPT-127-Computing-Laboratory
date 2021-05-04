#include <stdio.h>
#include <math.h>

int main(void)
{
  float i = 0;
  scanf( "%f", &i );
if (i != 0 )
{
  printf("%.0lf ", floor(i));
  printf("%.0lf ", round(i));
  printf("%.0lf\n", ceil(i));
}
else
{

  printf("scanf error: (%.0f)\n", i);
}
 return 0;

}
