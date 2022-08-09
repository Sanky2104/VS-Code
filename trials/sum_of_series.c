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
    printf("\nSum: %f",sum);
}