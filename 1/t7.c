#include <stdio.h>
int main(void)
{
int i = 0;
int p = 0;
int n = scanf( "%d", &i);
while (n!= EOF)
{	
	for (p = 0; p < i; p++)
	{
	printf("#");

	}
printf("\n");
n = scanf( "%d", &i);
}
return 0;
}
