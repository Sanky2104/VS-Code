//Author: Sanskriti Gupta
//Date: 3 March 2022
//Aim: Implement queue data structure using linked list and its operations (Enqueue, Dequeue, Display)
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *start=NULL;
void enqueue(int data); //to insert an element in the end
int dequeue(); //to delete an element from the front
void display(); //to display all the elements
struct Node *create_node(); //to create a new node
int main()
{
    int data,choice,a;
    while(1)
    {
        printf("\n1. Insert ");
        printf("\n2. Delete ");
        printf("\n3. Display ");
        printf("\n4. Exit \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the element to be inserted: ");
                scanf("%d",&data);
                enqueue(data);
                break;
            case 2:
                a=dequeue();
                printf("\nDeleted Element: %d",a);
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
    return 0;
}
struct Node *create_node()
{
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    return temp;
}
void enqueue(int data)
{
    struct Node *ptr=start;
    struct Node *new=create_node();
    new->data=data;
    if(start==NULL)
    {
        start=new;
        new->next=NULL;
    }
    else
    {
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=new;
        new->next=NULL;
    }
}
int dequeue()
{
    int a=start->data;
    if(start==NULL)
    {
        printf("Underflow");
    }
    else
    {
        start=start->next;
        return a;
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
    printf("\n");
}