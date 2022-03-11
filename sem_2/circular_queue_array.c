//Author: Sanskriti Gupta
//Date: 1 March 2022
//Aim: Using circular array and functions implement queue data structure and its operations linke insert, delete
#include<stdio.h>
#include<stdlib.h>
# define CAPACITY 100
int queue[CAPACITY];
void enqueue(int data);
int dequeue();
void display();
int front,rear;
void main()
{
    front=-1;
    rear=-1;
    while(1)
    {
        int choice,data;
        printf("\n1. Insert Element: ");
        printf("\n2. Delete Element: ");
        printf("\n3. Display Queue: ");
        printf("\n4. Exit: \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d",&data);
                enqueue(data);
                //count++;
                break;
            case 2:
                printf("%d ",dequeue());
                //count--;
                break;
            case 3:
                display();
            case 4:
                exit(0);
            default:
                printf("Wrong choice");
        }
    }
}
void enqueue(int data)
{
    if((rear==CAPACITY && front==1 )|| (front==rear+1))
    {
        printf("Overflow");
    }
    else if(rear==CAPACITY)
    {
        rear=1;
    }
    else if(front==-1)
    {
        front=1;
        rear=1;
    }
    else
    {
        rear++;
    }
    queue[rear]=data;
}
int dequeue()
{
    int data;
    data=queue[front];
    if(front==-1)
    {
        printf("Underflow");
    }
    else if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else if(front==CAPACITY)
    {
        front=1;
    }
    else
    {
        front++;
    }
    return data;
}
void display()
{
    int i;
    if(front==-1)
    {
        printf("\nList is Empty.\n");
    }
    else if(front<rear)
    {
        for(i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
    }
    else
    {
        int temp=front;
        while(temp!=CAPACITY)
        {
            printf("%d ",queue[temp]);
            temp++;
        }
        temp==1;
        for(i=temp;i<rear;i++)
        {
            printf("%d ",queue[i]);
        }
        
    }
}
