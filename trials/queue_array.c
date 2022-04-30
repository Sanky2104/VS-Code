//Author: Sanskriti Gupta
//Date: 16 April 2022
//Aim: To implement queue using array
#include<stdio.h>
#include<stdlib.h>
#define capacity 100
int queue[capacity];
int front=-1,rear=-1;
void enqueue(int item)
{
    if(rear==capacity)
    {
        printf("\nOVERFLOW");
    }
    else if(front==-1)
    {
        front=0;
        rear++;
        queue[rear]=item;
    }
    else
    {
        rear++;
        queue[rear]=item;
    }
}
int dequeue()
{
    if(front==-1)
    {
        printf("\nUNDERFLOW");
    }
    else if(front>=0)
    {
        int i=queue[front];
        front++;
        return i;
    }
}
void display()
{
    for(int i=front;i<=rear;i++)
    {
        printf("%d ",queue[i]);
    }
}
void main()
{
    int choice, item;
    while(1)
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the element: ");
                scanf("%d",&item);
                enqueue(item);
                break;
            case 2:
                item=dequeue();
                printf("\nDeleted Element: %d",item);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nWrong Choice");
        }
    }
}