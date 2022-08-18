#include<stdio.h>
int second_largest();
void main()
{
    int n,i;
    printf("Enter a number: ");
    scanf("%d",&n);
    int arr[n];
    for(i = 0 ; i < n ; i++)
    {
        printf("Enter a number: ");
        scanf("%d",&arr[i]);
    }
    int largest=arr[0],second_largest=arr[0];
    for(i=0;i<n;i++)
    {
        if(arr[i]>largest)
        {
            largest=arr[i];
        }
    }
    for(i=0;i<n;i++)
    {
        if(arr[i]>second_largest && arr[i]!=largest)
        {
            second_largest=arr[i];
        }
    }
    printf("Second largest: %d",second_largest);
}