//Author: Sanskriti Gupta
//Aim: To check the number of times the sub-string occurs in the string
#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,m,j,count=0;
    char string[100],sub_string[100],buffer[100];
    printf("\nEnter the string: ");
    gets(string);
    printf("\nEnter the sub-string: ");
    gets(sub_string);
    n=strlen(string);
    m=strlen(sub_string);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m-1;j++)
        {
            buffer[j]=string[j];
        }
        if(buffer==sub_string)
        {
            count++;
        }
    }
    puts(buffer);
    printf("%d",count);
}