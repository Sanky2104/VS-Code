#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
    int n, i, item, res, temp;
    int a[n];
    double time_spent=0.0;
    printf("\nEnter the number of elements: ");
    scanf("%d",&n);
    for(i=0 ; i<n ; i++)
    {
        temp = rand();
        a[i] = temp;   
    }
    printf("\nArray: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nItem to be searched: ");
    scanf("%d",&item);
    time_t start = time(NULL);
    res = binary_search(a,0,n-1,item);
    time_t stop = time(NULL)-start;
    time_spent += (double)(stop)/CLOCKS_PER_SEC;
    if(res != -1)
    {
        printf("\nIndex of element: %d",res);
    }
    else
    {
        printf("\nNo such element");
    }
    printf("\nTime elapsed: %f seconds",time_spent);
}
int binary_search(int a[], int s, int e, int item)
{
    int mid = (s+e)/2;
    if(a[mid]==item)
    {
        return mid;
    }
    else if(item > a[mid])
    {
        binary_search(a, mid+1, e, item);
    }
    else if(item < a[mid])
    {
        binary_search(a,s,mid-1,item);
    }
    return -1;
}