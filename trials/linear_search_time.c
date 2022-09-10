#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    long n;
    int i, item, count=0;
    printf("\nEnter the number of elements: ");
    scanf("%ld",&n);
    long a[n];
    for(i=0 ; i<n ; i++)
    {
        a[i] = rand();   
    }
    printf("\nArray: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n\nItem to be searched: ");
    scanf("%d",&item);
    clock_t start,end;
    start = clock();
    for(i=0 ; i<n ; i++)
    {
        if(a[i]==item)
        {
            break;
        }
        else
        {
            count++;
        }
    }
    end = clock();
    double time_spent = (double)(end-start)/CLOCKS_PER_SEC;
    if(count == n)
    {
        printf("\nNo such element");

    }
    else
    {
        printf("\nIndex of element: %d",count);
    }
    printf("\nTime elapsed: %f seconds",time_spent);
    return 0;
}