//Author: Sanskriti Gupta
//Aim: To read numbers from a file then store it an array and then write it on another file
#include<stdio.h>
int array[50],i=1;
void read(FILE *ptr)
{
    int a=0;
    while(!feof(ptr))
    {
        fscanf(ptr,"%d",&array[a]);
        a++;
        i++;
    }
}
void print()
{
    for(int j=0;j<i-1;j++)
    {
        printf("%d ",array[j]);
    }
}
void _write()
{
    FILE *ptr1=fopen("text1.txt","a");
    for(int j=0;j<i-1;j++)
    {
        fprintf(ptr1,"%d ",array[j]);
    }
}
int main()
{
    FILE *ptr=fopen("text.txt","r");
    if(ptr==NULL)
    {
        printf("\nNo such file");
    }
    else
    {
        read(ptr);
    }
    print();
    _write();
    return 0;
}