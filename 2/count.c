#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
unsigned long charcount = 0;
unsigned long wordcount = 0;
unsigned long linecount = 0;
int standard_input=0;
int flag = 0;
int previous = 0;

while ((standard_input = getchar()) != EOF){

	charcount++;
	if (standard_input == '\n')
	{
	linecount++;
	}
	if (isalpha(standard_input)== 0 && standard_input != '\'')
	{
		flag = 0;
	}
	else 
	{
		flag = 1;
	}
	if(flag == 0 && previous == 1)
	{
		wordcount++;
	}

previous = flag;
}
printf( "%lu %lu %lu\n", charcount, wordcount, linecount );
return 0;
}