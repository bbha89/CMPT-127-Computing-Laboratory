#include <stdio.h>
#include <math.h>

int main()
{
int x = 0;
int y = 0;
int z = 0;
int i = 0;
int j = 0;
int p = 0;
scanf ("%d %d %d", &x, &y, &z);
if(x==1 && z==1)
{
	printf("#\n");
}
if(x != 1 && z!= 1)
{
j = z-1;
int left = floor( j * (x/(2.0*z)) );
int right = ceil( (x-1) + -j * (x/(2.0*z)) );
for(int i =0;i<=right;i++)
{
	if(i<left)
	{
		printf(" ");
	}
	if(i>=left)
	{
		printf("#");
	}
}
printf("\n");	
for(j = z-2; j>0;j--){
	int left = floor( j * (x/(2.0*z)) );
	int right = ceil( (x-1) + -j * (x/(2.0*z)) );
	for(int i = 0; i<right;i++)
	{
		if(i < left)
		{
			printf(" ");
		}
		if(i==left)
		{
			printf("#");
		}
		if(i >left && i<=right)
		{
			printf(".");
		}
	}
printf("#\n");
}
for(int i = 0;i<x;i++)
{
	printf("#");
}
printf("\n");
}
}
