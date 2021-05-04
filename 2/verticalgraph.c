 #include <stdio.h>

int main(){

int len=0;
int height=0;
int values[80];
int arr[80][80];
int i = 0;
int j = 0;
int num = 0;
int input=scanf("%d", &num);
while (input!=EOF)//Knows the max height/length
{
	values[i] = num;
    i++;//ready to store next input
    len++;//number of elements
    if (num>height)
    {
      height=num;//highest height maximum number**
    }
    if(i >=80)
    {
    	break;//breaks if input is greater than 80
    }
input=scanf("%d", &num);
}
  // for (i=0;i<len;i++){//Checking whats in the array
  //   printf("%d ",values[i]);//orderred input(1,1,3,1)}
int current = height;//3
for(i=0;i<height;i++){//for matrix
	for(j=0;j<len;j++)
	{
		if(values[j] >= current)
		{
			arr[j][i] = 1;//sets true
		}
	}
current--;//lowers the height by 1 so at the very bottom everything will be '#'
}
for(i=0;i<height;i++){
	for(j=0;j<len;j++){
		if (arr[j][i]==1)//matrix true
    	{
        	printf("#");
      	}
      	else
      	{
        	printf(" ");
      	}
    }
printf("\n");
}

return 0;
}
