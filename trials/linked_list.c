//Author: Sanskriti Gupta
//Date: 10 March 2022
//Aim: To perform insert/delete at beginning, end and position in a linked list
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *link;
};
struct Node *start=NULL;
struct Node *create_node();
void insert_beg(int item);
void insert_pos(int item, int pos);
void insert_end(int item);
int delete_beg();
int delete_pos(int pos);
int delete_end();
void display();
void main()
{
    int item,pos,choice;
    while(1)
    {
        printf("\n1. Insert at beginning");
        printf("\n2. Insert at position");
        printf("\n3. Insert at end");
        printf("\n4. Delete at beginning");
        printf("\n5. Delete at position");
        printf("\n6. Delete at end");
        printf("\n7. Display");
        printf("\n8. Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("\nEnter the element: ");
            scanf("%d",&item);
            insert_beg(item);
            break;
            case 2:
            printf("\nEnter the element: ");
            scanf("%d",&item);
            printf("\nEnter the position: ");
            scanf("%d",&pos);
            insert_pos(item,pos);
            break;
            case 3:
            printf("\nEnter the element: ");
            scanf("%d",&item);
            insert_end(item);
            break;
            case 4:
            item=delete_beg();
            printf("\nDeleted Item: %d",item);
            break;
            case 5:
            printf("\nEnter the position: ");
            scanf("%d",&pos);
            item=delete_pos(pos);
            printf("\nDeleted Item: %d",item);
            break;
            case 6:
            item=delete_end();
            printf("\nDeleted Item: %d",item);
            break;
            case 7:
            display();
            break;
            case 8:
            exit(0);
            default:
            printf("\nWrong Choice\n");
        }
    }
}
struct Node *create_node()
{
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    return temp;
}
void insert_beg(int item)
{
    struct Node *new=create_node();
    new->data=item;
    if(start==NULL)
    {
        new->link=NULL;
        start=new;
    }
    else
    {
        new->link=start;
        start=new;
    }
}
void insert_end(int item)
{
    struct Node *new=create_node();
    struct Node *ptr=start;
    new->data=item;
    new->link=NULL;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=new;
}
void insert_pos(int item,int pos)
{
    struct Node *new=create_node();
    struct Node *ptr=start;
    new->data=item;
    while(ptr!=pos)
    {
        ptr=ptr->link;
    }
    new->link=ptr->link;
    ptr->link=new;
}
int delete_beg()
{
    int a=start->data;
    if(start==NULL)
    {
        printf("\nUnderflow");
    }
    else
    {
        start=start->link;
    }
    return a;
}
int delete_end()
{
    int a;
    struct Node *ptr=start;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    a=ptr->link->data;
    ptr->link=NULL;
    return a;
}
int delete_pos(int pos)
{
    int a;
    struct Node *ptr=start;
    while(pos!=ptr)
    {
        ptr=ptr->link;
    }
    ptr=ptr->link;
}
void display()
{
    struct Node *ptr=start;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
}