#include<stdio.h>
void main()
{
    int a,b;
    printf("\nEnter 2 numbers: ");
    scanf("%d%d",&a,&b);
    a=a+b;
    b=a-b;
    a=a-b;
    printf("\nAfter swapping: ");
    printf("a= %d",a);
    printf("\tb=%d",b);
}