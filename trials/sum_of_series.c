#include<stdio.h>
void main()
{
    int n,i;
    float sum=0;
    printf("\nEnter the value of n: ");
    scanf("%d",&n);
    while(n!=0)
    {
        sum=sum + (1.0/n);
        n--;
    }
    if(n==1)
    {
        printf("\nSum: 1.00");
    }
    else if(n==0)
    {
        printf("\nSum: 0.00");
    }
    else
    {
        printf("\nSum: %f",sum);
    }
}