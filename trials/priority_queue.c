//Author: Sanskriti Gupta
//Date: 11 March 2022
/*Aim: Write a program that implements priority queue with the help of linked list representation.
Write each operation (enqueue,dequeue and display) as a seperate fucntion. Also, write main function as
a menu driven mode mode that demonstrates use of all operation*/
#include<stdio.h>
#include<stdlib.h>
#define max 100
void enqueue(int);
int dequeue();
void create(); //function to create an empty priority queue
void check(int);
void display();
int pri_que[max],front,rear;
void main()
{
    int n,choice;
    create();
    while(1)
    {
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("\nEnter the element: ");
            scanf("%d",&n);
            enqueue(n);
            break;
            case 2:
            n=dequeue();
            printf("\nDeleted Item: %d",n);
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
void create()  //function to create an empty priority queue
{
    front=-1;
    rear=-1;
}
void enqueue(int data)  //function to insert value into priority queue
{
    if(rear>=max-1)
    {
        printf("\nOverflow");
    }
    if(front==-1 && rear==-1)
    {
        front++;
        rear++;
        pri_que[rear]=data;
    }
    else
    {
        check(data);
        rear++;
    }
}
void check(int data)  //fucntion to check priority and place element
{
    int x,j;
    for(x=0;x<=rear;x++)
    {
        if(data>=pri_que[x])
        {
            for(j=rear+1;j>x;j--)
            {
                pri_que[j]=pri_que[j-1];
            }
            pri_que[x]=data;
            return ;
        }
    }
    pri_que[x]=data;
}
int dequeue() // function to delete an element from the queue
{
    int x=pri_que[front];
    if(front==-1 && rear==-1)
    {
        printf("\nUnderflow");
    }
    else
    {
        front--;
        return x;
    }
}
void display()
{
    if(front==-1 && rear==-1)
    {
        printf("\nEmpty Queue");
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",pri_que[i]);
        }
    }
    front=0;
}