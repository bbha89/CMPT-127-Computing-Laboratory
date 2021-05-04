#include <stdio.h>
int main(void)
{
int i = 0;
int j = 0;
int k = 0;

int p = 0;
int q = 0;
int r = 0;


int a = scanf("%d %d %d", &i,&j,&k);


if (j == 1)
{
	printf("#");
}
else{
	for (p = 0; p < i; p++)
	{
		printf("#");
	}
printf("\n");
for (q = 0; q < j-2; q++)
	{
		printf("#");
		for(r = 0; r < i-2;r++)
		{
			printf(".");
		}
		printf("#");
printf("\n");
	}


for (p = 0; p < i; p++)
	{
		printf("#");
	}
}
printf("\n");
return 0;
}