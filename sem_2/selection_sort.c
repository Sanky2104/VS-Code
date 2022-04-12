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
void selection_sort(int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min=arr[i];
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<min)
            {
                int t=arr[i];
                arr[i]=arr[j];
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
    selection_sort(n);
    print(n);
    return 0;
}