//Author: Sanskriti Gupta
//Date: 11 March 2022
/*Aim: Write a program that implements priority queue with the help of linked list representation.
Write each operation (enqueue,dequeue and display) as a seperate fucntion. Also, write main function as
a menu driven mode mode that demonstrates use of all operation*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Node 
{
    int info;
    int priority;
    struct Node *link;
}Node;
Node *front=NULL;
void insert(int data, int priority); //for insertion
int del(); //for deletion
void display(); //for displaying the queue
void main()
{
    int choice,data,priority;
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
            scanf("%d",&data);
            printf("\nEnter the priority: ");
            scanf("%d",&priority);
            insert(data,priority);
            break;
            case 2:
            data=del();
            printf("\nDeleted Item: %d\n",data);
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
void insert(int data, int priority)
{
    Node *temp,*q;
    temp=(Node *)malloc(sizeof(Node));
    temp->info=data;
    temp->priority=priority;
    if(front==NULL || priority<front->priority)
    {
        temp->link=front;
        front=temp;
    }
    else
    {
        q=front;
        while(q->link!=NULL && q->link->priority<=priority)
        {
            q=q->link;
        }
        temp->link=q->link;
        q->link=temp;
    }
}
int del()
{
    int item;
    Node *temp;
    if(front==NULL)
    {
        printf("\nUnderflow");
        return 0;
    }
    else
    {
        temp=front;
        item=temp->info;
        front=front->link;
        free(temp);
        return item;
    }
}
void display()
{
    Node *ptr;
    ptr=front;
    if(front==NULL)
    {
        printf("\nEmpty Queue");
    }
    else
    {
        printf("\nQueue is: \n");
        printf("Priority\tItem\n");
        while(ptr!=NULL)
        {
            printf("%d\t\t%d\n",ptr->priority,ptr->info);
            ptr=ptr->link;
        }
    }
}