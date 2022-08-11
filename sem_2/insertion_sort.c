//Author: Sanskriti Gupta
//Date: 12 April 2022
//Aim: Implementing insertion sort
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
void insertion_sort(int n)
{
    int i;
    for(i=1;i<n;i++)
    {
        int key=arr[i];
        int k=i-1;
        while(key>=0 && key<arr[k])
        {
            arr[k+1]=arr[k];
            k--;
            arr[k+1]=key;
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
    insertion_sort(n);
    print(n);
    return 0;
}