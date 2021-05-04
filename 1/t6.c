#include <stdio.h>
#include <math.h>

int main(void)
{
float i = 0;
float a = -100000;
float b = 100000;
float times = 0;
float sum = 0;
int n = scanf( "%f", &i );
while (!(n == EOF))
{
if (i <= b)
	{	
		b = i;
	}

if (i >= a)
	{
		a = i;
	}

times = times + 1;
sum = sum + i;
n = scanf( "%f", &i );
}

float mean = sum / times;
printf("%.2f %.2f %.2f\n", b, a, mean);
return 0;
}
