#include<stdio.h>
void main()
{
    int i, j, k;
    int m1[3][3], m2[3][3], m3[3][3];
    printf("\nMATRIX 1");
    for(i = 0 ; i < 3 ; i++)
    {
        for(j = 0 ; j < 3 ; j++)
        {
            printf("\nEnter a number: ");
            scanf("%d",&m1[i][j]);
        }
    }
    printf("\nMATRIX 2");
    for(i = 0 ; i < 3 ; i++)
    {
        for(j = 0 ; j < 3 ; j++)
        {
            printf("\nEnter a number: ");
            scanf("%d",&m2[i][j]);
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            m3[i][j] = 0;
            for(k=0;k<3;k++)
            {
                m3[i][j] += m1[i][k]*m2[k][j]; 
            }
        }
    }
    printf("\nMatrix 3: \n");
    for(i = 0 ; i < 3 ; i++)
    {
        for(j = 0 ; j < 3 ; j++)
        {
            printf("%d ",m3[i][j]);
        }
        printf("\n");
    }
}