//Author: Sanskriti Gupta
//Date: 21 March 2022
//Aim: To implement first fit memory allocation
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int p[10],pno,bno,i,j,flags[10],allocation[10]; //p=process ID, b=block size, ps=process size
    float ps[10],b[i];
    printf("\nEnter the number of processes: ");
    scanf("%d",&pno);
    printf("\nEnter the number of blocks: ");
    scanf("%d",&bno);
    for(i-0;i<10;i++)
    {
        flags[i]=0;
        allocation[i]=-1;
    }
    for(i=0;i<pno;i++)
    {
        printf("\nEnter the process ID and process size: ");
        scanf("%d%f",&p[i],&ps[i]);
    }
    for(i=0;i<bno;i++)
    {
        printf("\nEnter the block size for P[%d]: ",i+1);
        scanf("%f",&b[i]);
    }
    for(i=0;i<pno;i++)
    {
        for(j=0;j<bno;j++)
        {
            if(flags[i]==0 && b[i]>=ps[i])
            {
                allocation[j]=i;
                flags[j]=i;
                break;
            }
        }
    }
    printf("\nBlock No.\tSize\tProcess no.\tSize");
    for(i=0;i<bno;i++)
    {
        printf("\n%d\t%d",i+1,b[i]);
        if(flags[i]==1)
        {
            printf("%d\t%d",allocation[i]+1,ps[allocation[i]]);
        }
        else
        {
            printf("\nNot allocated");
        }
    }
    return 0;
}