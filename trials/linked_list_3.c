//Author: Sanskriti Gupta
//Date: 23 July 2022
//Aim: To implement a singly linked list using operations like insertion, deletion and display

//YE WALA SAHI HAI

#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *create_node()
{
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    return temp;
}
struct Node *start=NULL;
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
        }
        new->next=ptr->next;
        ptr->next=new;
    }
}
int del_beg()
{
    if(start==NULL)
    {
        printf("EMPTY LIST !!!");
    }
    else
    {
        int i=start->data;
        struct Node *temp=start;
        start=start->next;
        free(temp);
        return i;
    }
}
int del_end()
{
    if(start==NULL)
    {
        printf("\nEMPTY LIST !!!");
    }
    else
    {
        struct Node *ptr=start, *temp;
        while(ptr->next->next!=NULL)
        {
            ptr=ptr->next;
        }
        temp=ptr->next;
        int i=temp->data;
        ptr->next=NULL;
        free(temp);
        return i;
    }
}
int del_pos(int pos)
{
    if(start==NULL)
    {
        printf("\nEMPTY LIST !!!");
    }
    else
    {
        int p=1,i;
        struct Node *ptr=start, *temp;
        while(p<pos-1)
        {
            ptr=ptr->next;
        }
        temp=ptr->next;
        ptr->next=ptr->next->next;
        i=temp->data;
        free(temp);
        return i;
    }
}
void display()
{
    if(start==NULL)
    {
        printf("\nEMPTY LIST !!!");
    }
    else
    {
        struct Node *ptr=start;
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
}
void main()
{
    int item, pos, choice;
    while(1)
    {
        printf("\n1. Insert at beginning");
        printf("\n2. Insert at end");
        printf("\n3. Insert at position");
        printf("\n4. Delete at beginning");
        printf("\n5. Delete at end");
        printf("\n6. Delete at position");
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
                insert_end(item);
                break;
            case 3:
                printf("\nEnter the item: ");
                scanf("%d",&item);
                printf("\nEnter the position: ");
                scanf("%d",&pos);
                insert_pos(item,pos);
                break;
            case 4:
                item=del_beg();
                printf("\nDeleted Item: %d",item);
                break;
            case 5:
                item=del_end();
                printf("\nDeleted Item: %d",item);
                break;
            case 6:
                printf("\nEnter the position: ");
                scanf("%d",&pos);
                item=del_pos(pos);
                printf("\nDeleted Item: %d",item);
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("\nWrong Choice, Try Again !!!");
        }
    }
}