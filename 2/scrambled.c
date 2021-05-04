    #include <stdio.h>
    // declaration of function implemented in scrambled.c
    int scrambled( unsigned int a[], unsigned int b[], unsigned int len )
     {

    int k = 0;
    int l = 0;
    int sum = 0;
    int sum_2 = 0;
    if(len == 0)
    	{
    		return 1;
    	}
for (k = 0; k<len; k++)
{
	sum = sum + a[k];
}
for (l = 0; l<len; l++)
{
	sum_2 = sum_2 + b[l];
}
if (sum == sum_2)
{
	return 1;
}
else
{
	return 0;
}

}
