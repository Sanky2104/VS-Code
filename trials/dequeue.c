//Author: Sanskriti Gupta
//Date: 4 April 2022
/*Aim: Using array and functions implement double ended queue (input restricted dequeue and output 
restricted dequeue ) and its operations*/
#include<stdio.h>
#define CAPACITY 100
int dequeue[CAPACITY];
void ins_beg(int item);
void ins_end(int item);
int del_beg();
int del_end();
void main()
{
    int c,choice,item;
    printf("\n1. Input Restricted Dequeue");
    printf("\n2. Output Restricted Dequeue");
    scanf("%d",&c);
    if(c==1)
    {
        printf("\nINPUT restricted dequeue");
        while(1)
        {
            pritnf("\n1. Insetion");
            printf("\n2. Deletion from beginning");
            printf("\n3. Deletion from end");
            printf("\n4. Exit\n");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                    printf("\nEnter the element: ");
                    scanf("%d",&item);
                    ins_end(item);
                    break;
                case 2:
                    item=del_beg();
                    printf("\nDeleted Item: %d",item);
                    break;
                case 3:
                    item=del_end();
                    printf("\nDeleted Item: %d",item);
                    break;
                case 4:
                    exit(0);
                default:
                    printf("\nWrong Choice");
            }
        }
    }
    else if(c==2)
    {
        printf("\nOUTPUT restricted dequeue");
        while(1)
        {
            printf("\n1. Insertion from beginning");
            printf("\n2. Insertion from end");
            printf("\n3. Delete");
            printf("\n4. Exit\n");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                    printf("\nEnter the element: ");
                    scanf("%d",&item);
                    ins_beg(item);
                    break;
                case 2;
                    printf("\nEnter the element: ");
                    scanf("%d",&item);
                    break;
            }
        }
    }
    else
    {
        printf("\nWrong Choice Buddy !!!");
    }
}