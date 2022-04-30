//Author: Sanskriti Gupta
//Aim: Read the numbers from a text file sort them into an array using 'Selection Sort' algorithm and
//write back in another text file
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
    FILE *ptr1=fopen("selection.txt","a");
    for(int j=1;j<i;j++)
    {
        fprintf(ptr1,"%d ",array[j]);
    }
}
void selection_sort()  
{  
    int j,t,small;  
    for (j = 0; j < i-1; j++)    // One by one move boundary of unsorted subarray  
    {  
        small = j; //minimum element in unsorted array   
        for (t = j+1; t < i; t++)  
        if (array[t] < array[small])
        {
            small=t;
        }
    // Swap the minimum element with the first element  
    int temp = array[small];  
    array[small] = array[j];  
    array[j] = temp;  
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
    selection_sort();
    write();
    printf("After Sorting: ");
    for(int j=1;j<i;j++)
    {
        printf("%d ",array[j]);
    }
}