//Author: Sanskriti Gupta
//Date: 18 January 2022
//Aim: Find the total number of alphabets, digits or special characters in a string
#include<stdio.h>
#include<string.h>
void dig_char_alphabets(char *str, int n);
int main()
{
char str[100];
int n;
printf("Enter a string: ");
gets(str);
n=strlen(str);
dig_char_alphabets(str,n);
return 0;
}
void dig_char_alphabets(char *str,int n)
{
int i, count_char=0,count_dig=0,count_alpha=0;
for(i=0;i<n;i++)
{
	if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z'))
	{
		count_alpha+=1;
	}
	else if(str[i]>='0' && str[i]<='9')
	{
		count_dig+=1;
	}
	else
	{
		count_char+=1;
	}
}
printf("The total number of characters in the string: %d\n",count_alpha);
printf("The total number of digits in the string: %d\n",count_dig);
printf("The total number of special characters in the string: %d\n",count_char);
}