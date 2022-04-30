//Author: Sanskriti Gupta
//Date: 27 April 2022
//Aim: To implement insertion and deletion in array
#include<stdio.h>
#include<stdlib.h>
int arr[20],n;
void ins_front(int item)
{
    for(int i=n;i>=0;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[0]=item;
    n++;
}
void ins_end(int item)
{
    arr[n]=item;
    n++;
}
int del_front()
{
    int item=arr[0];
    for(int i=0;i<n-1;i++)
    {
        arr[i]=arr[i+1];
    }
    n--;
    return item;
}
int del_end()
{
    int item=arr[n-1];
    n--;
    return item;
}
void display()
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
void main()
{
    int choice,item;
    printf("\nEnter the number of elements: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\nEnter the element: ");
        scanf("%d",&arr[i]);
    }
    while(1)
    {
        printf("\n1. Insert at front");
        printf("\n2. Insert at end");
        printf("\n3. Delete at front");
        printf("\n4. Delete at end");
        printf("\n5. Display");
        printf("\n6. Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the element: ");
                scanf("%d",&item);
                ins_front(item);
                break;
            case 2:
                printf("\nEnter the element: ");
                scanf("%d",&item);
                ins_end(item);
                break;
            case 3:
                item=del_front();
                printf("\nDeleted Item: %d",item);
                break;
            case 4:
                item=del_end();
                printf("\nDeleted Item: %d",item);
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("\nWrong Choice");
        }
    }
}