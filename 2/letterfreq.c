#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
int input=0;
float freq = 0;
float freqa = 0;
int i = 0;
int abc[26];
float total = 0;
char letter;
int num = 0;
int numa = 0;
int answer = 0;

for(i=0;i<26;i++)
{
	abc[i] = 0;//the alphabets starting at 0
	//(makes this start anew not 26 random junk)
}
while ((input = getchar()) != EOF){
	if (isalpha(input) != 0)// if the input is an alphabet
	{
		if(input >=65 && input <= 90)// A-Z
		{
			total++;//increase total letters by 1
			input += 32;// makes this lower case
			letter = input;// letter to be printed
		}
		else if(input >= 97 && input <= 122)//a-z
		{
			total++;//increase total letters by 1
			letter = input;//letter to be printed
			//printf("single%d\n", letter);
			//printf("total%d\n", total);
		}
	abc[input-'a']+=1;
	//printf("letters %d\n",abc[input-'a']);
	// Changings the input into number value.
	//total of each letter
	}//ex. abccc: a1,b1,c1,c2,c3
}
for(i=0;i<26;i++)
{
    if (abc[i]!=0)
    {
      letter=i+'a';// Changes back to letter value.
      freq=(abc[i]/total);
      printf( "%c %.4f\n", letter, freq);
	}
}
return 0;
}