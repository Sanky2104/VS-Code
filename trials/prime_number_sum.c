#include<stdio.h>
int isprime(int n);
void main()
{
    int n,i,j,flag=0;
    int array[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    for(j=0;j<n;j++)
    {
        if(array[j]==1)
        {
            printf("-1 -1\n");
        }
        for(i=2;i<=array[j]/2;i++)
        {
            if(isprime(array[j])==1)
            {
                if(isprime(array[j]-i)==1)
                {
                    printf("%d %d\n",i,array[j]-i);
                    flag=1;
                }
            }
        }
    }
}
int isprime(int n)
{
    int i,result=1;
    for(i=2;i<=n/2;i++)
    {
        if(n%i==0)
        {
            result=0;
        }
    }
    return result;
}