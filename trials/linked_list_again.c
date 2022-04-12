//Author: Sanskriti Gupta
//Date: 25 March 2022
//Aim: To create a single linked list and implement all the insertion/deleteion operations
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *start=NULL;
void insert_beg(int item);
void insert_pos(int item, int pos);
void insert_end(int item);
int delete_beg();
int delete_pos(int pos);
int delete_end();
void display();
struct Node *create_node();
void main()
{
    int choice, item, pos;
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
                printf("\nWrong Choice");
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
        start=new;
        new->next=NULL;
    }
    else
    {
        new->next=start;
        start=new;
    }
}
void insert_pos(int item, int pos)
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
        int p=1;
        struct Node *ptr=start;
        while(p<pos-1)
        {
            ptr=ptr->next;
            p++;
        }
        new->next=ptr->next;
        ptr->next=new;
    }
}
void insert_end(int item)
{
    struct Node *new=create_node();
    new->data=item;
    new->next=NULL;
    if(start==NULL)
    {
        start=new;
    }
    else
    {
        struct Node *ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=new;
    }
}
int delete_beg()
{
    if(start==NULL)
    {
        printf("\nUnderflow");
    }
    else
    {
        struct Node *ptr=start;
        int i=start->data;
        start=start->next;
        free(ptr);
        return i;
    }
}
int delete_pos(int pos)
{
    if(start==NULL)
    {
        printf("\nUnderflow");
    }
    else
    {
        struct Node *ptr=start,*ptr1;
        int p=1,i;
        while(p<=pos-1)
        {
            ptr1=ptr;
            ptr=ptr->next;
            p++;
        }
        i=ptr->data;
        ptr1->next=ptr->next;
        free(ptr);
        return i;
    }
}
int delete_end()
{
    int i=0;
    if(start==NULL)
    {
        printf("\nUnderflow");
    }
    else
    {
        struct Node *ptr=start,*temp;
        while(ptr->next->next!=NULL)
        {
            ptr=ptr->next;
        }
        i=ptr->next->data;
        ptr->next=NULL;
        return i;
    }
}
void display()
{
    struct Node *ptr=start;
    if(start==NULL)
    {
        printf("\nThe List is Empty");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("%d->",ptr->data);
            ptr=ptr->next;
        }
    }
}