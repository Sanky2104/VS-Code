//Author: Sanskriti Gupta
//Aim: Read the numbers from a text file sort them into an array using 'Quick Sort' algorithm and 
//write it back in another text file.
#include <stdio.h>
int array[50],t=0;
void read(FILE *ptr)
{
    int a=0;
    while(!feof(ptr))
    {
        fscanf(ptr,"%d",&array[a]);
        a++;
        t++;
    }
}
void write()
{
    FILE *ptr1=fopen("quick.txt","a");
    for(int j=1;j<t;j++)
    {
        fprintf(ptr1,"%d ",array[j]);
    }
}
int partition(int start, int end)  
{  
    int pivot = array[end]; // pivot element  
    int i = (start - 1);  
  
    for (int j = start; j <= end - 1; j++)  
    {  
         
        if (array[j] < pivot)  
        {  
            i++;  
            int t = array[i];  
            array[i] = array[j];  
            array[j] = t;  
        }  
    }  
    int t=array[i+1];  
    array[i+1]=array[end];  
    array[end] =t;  
    return (i+1);  
}  
void quick(int start, int end)   
{  
    if (start<end)  
    {  
        int p=partition(start,end); 
        quick(start,p-1);  
        quick(p+1,end);  
    }  
}  
void main()  
{  
    int n;
    FILE *ptr=fopen("text1.txt","r");
    if(ptr==NULL)
    {
        printf("\nNo such file");
    }
    else
    {
        read(ptr);
    }
    printf("\nBeofre Sorting: ");
    for(int j=0;j<t-1;j++)
    {
        printf("%d ",array[j]);
    }
    printf("\n");
    quick(0,t-1);
    write();
    printf("After Sorting: ");
    for(int j=1;j<t;j++)
    {
        printf("%d ",array[j]);
    }
}