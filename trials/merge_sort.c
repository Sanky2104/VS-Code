//Author: Sanskriti Gupta
//Aim: Read the numbers from a text file sort them into an array using 'Merge Sort' algorithm and write
//back in another file
#include<stdio.h>
int array[50],i=0,n1,n2;
int L[25],R[25];
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
    FILE *ptr1=fopen("merge.txt","a");
    for(int j=1;j<i;j++)
    {
        fprintf(ptr1,"%d ",array[j]);
    }
}
void merge(int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    /* create temp arrays */
    int L[n1], R[n2];
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            array[k] = L[i];
            i++;
        }
        else 
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
        // Sort first and second halves
        mergeSort(l, m);
        mergeSort(m + 1, r);
        merge(l, m, r);
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
    mergeSort(0,i-1);
    write();
    printf("After Sorting: ");
    for(int j=1;j<i;j++)
    {
        printf("%d ",array[j]);
    }
}