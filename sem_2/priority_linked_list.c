//Author: Sanskriti Gupta
//Aim: To implement priority queue using linked list
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    int priority;
    struct Node *next;
};
struct Node *start=NULL;
struct Node *create_node();
void insert(int item, int p);
int delete();
void display();
void main()
{
    int choice,item,p;
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
            scanf("%d",&item);
            printf("\nEnter the priority: ");
            scanf("%d",&p);
            insert(item,p);
            break;
            case 2:
            item=delete();
            printf("\nDeleted Item: %d",item);
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
struct Node *create_node()
{
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    return temp;
}
void insert(int item, int p)
{
    struct Node *new=create_node();
    struct Node *ptr=start;
    new->data=item;
    new->priority=p;
    if(start==NULL)
    {
        start=new;
        new->next=NULL;
    }
    else
    {
        if(start->priority>=p)
        {
            new->next=start;
            start=new;
        }
        else
        {
            while(ptr->priority<p)
            {
                ptr=ptr->next;
            }
            new->next=ptr->next;
            ptr->next=new;
        }
    }
}
int delete()
{
    int i;
    if(start==NULL)
    {
        printf("\nEmpty Queue");
    }
    else
    {
        i=start->data;
        start=start->next;
        return i;
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