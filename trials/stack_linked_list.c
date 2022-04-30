//Author: Sanskriti Gupta
//Date: 16 April 2022
//Aim: To implement stack using linked list

//YE WALA SAHI HAI

#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *start=NULL;
struct Node *create_node()
{
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    return temp;
}
void push(int item)
{
    struct Node *new=create_node();
    new->data=item;
    if(start==NULL)
    {
        start=new;
        new->next=NULL;
    }
    else
    {
        new->next=start;
        start=new;
    }
}
int pop()
{
    if(start==NULL)
    {
        printf("\nEMPTY STACK");
    }
    else
    {
        int i=start->data;
        start=start->next;
        return i;
    }
}
int peek()
{
    if(start==NULL)
    {
        printf("\nEMPTY STACK");
    }
    else
    {
        return start->data;
    }
}
void display()
{
    struct Node *ptr=start;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
void main()
{
    int choice, item;
    while(1)
    {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the element: ");
            scanf("%d",&item);
            push(item);
            break;
        case 2:
            item=pop();
            printf("\nDeleted Element: %d",item);
            break;
        case 3:
            item=peek();
            printf("\nTopmost item: %d",item);
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("\nWrong choice");
        }
    }
}