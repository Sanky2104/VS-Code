//Author: Sanskriti Gupta
//Date: 12 April 2022
//Aim: Implementing bubble sort
#include<stdio.h>
int arr[50];
void ins_element(int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nEnter the element: ");
        scanf("%d",&arr[i]);
    }
}
void bubble_sort(int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int t=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=t;
            }
        }
    }
}
void print(int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
int main()
{
    int n,i;
    printf("\nEnter the number of elements: ");
    scanf("%d",&n);
    ins_element(n);
    bubble_sort(n);
    print(n);
    return 0;
}