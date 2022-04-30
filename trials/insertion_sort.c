//Author: Sanskriti Gupta
//Aim: Read the numbers from a text file sort them into an array using 'Insertion Sort' algorithm and
//write back in another text file.
#include<stdio.h>
int array[50],i=0;
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
void write()
{
    FILE *ptr1=fopen("text2.txt","a");
    for(int j=1;j<i;j++)
    {
        fprintf(ptr1,"%d ",array[j]);
    }
}
void inseration_sort(int i)
{
    int j;
    for(j=1;j<i;j++)
    {
        int temp=array[j];
        int k=j-1;
        while(k>=0 && array[k]>temp)
        {
            array[k+1]=array[k];
            k--;
        }
        array[k+1]=temp;
    }
}
void main()
{
    FILE *ptr=fopen("text1.txt","r");
    if(ptr==NULL)
    {
        printf("\nNo such file");
    }
    else
    {
        read(ptr);
    }
    printf("\nBefore Sorting: ");
    for(int j=0;j<i-1;j++)
    {
        printf("%d ",array[j]);
    }
    printf("\n");
    inseration_sort(i);
    write();
    printf("After Sorting: ");
    for(int j=1;j<i;j++)
    {
        printf("%d ",array[j]);
    }
}