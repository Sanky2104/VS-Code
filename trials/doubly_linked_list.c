//Author: Sanskriti Gupta
//Date: 30 April 2022
//Aim: To implement doubly linked list

//YE WALA SAHI HAI

#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next,*prev;
};
struct Node *start=NULL;
struct Node *create_node()
{
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    return temp;
}
void ins_beg(int item)
{
    struct Node *new=create_node();
    new->data=item;
    if(start==NULL)
    {
        start=new;
        new->next=NULL;
        new->prev=NULL;
    }
    else
    {
        new->next=start;
        start=new;
        new->prev=NULL;
    }
}
void ins_end(int item)
{
    struct Node *new=create_node();
    new->data=item;
    if(start==NULL)
    {
        start=new;
        new->next=NULL;
        new->prev=NULL;
    }
    else
    {
        struct Node *ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        new->prev=ptr;
        ptr->next=new;
        new->next=NULL;
    }
}
void ins_pos(int item, int pos)
{
    struct Node *new=create_node();
    new->data=item;
    if(start==NULL)
    {
        start=new;
        new->next=NULL;
        new->prev=NULL;
    }
    else
    {
        int p=1;
        struct Node *ptr=start;
        while(p<pos-1)
        {
            ptr=ptr->next;
        }
        new->prev=ptr;
        new->next=ptr->next;
        ptr->next=new;
    }
}
int del_beg()
{
    if(start==NULL)
    {
        printf("\nList is Empty");
    }
    else
    {
        int i=start->data;
        start->next->prev=NULL;
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
        printf("\nList is Empty");
    }
    else
    {
        struct Node *ptr=start;
        while(ptr->next->next!=NULL)
        {
            ptr=ptr->next;
        }
        int i=ptr->next->data;
        struct Node *temp=ptr->next;
        ptr->next=NULL;
        free(temp);
        return i;
    }
}
int del_pos(int pos)
{
    if(start==NULL)
    {
        printf("\nList is Empty");
    }
    else
    {
        int p=1;
        struct Node *ptr=start;
        while(p<pos-1)
        {
            ptr=ptr->next;
        }
        int i=ptr->next->data;
        struct Node *temp=ptr->next;
        ptr->next->next->prev=ptr;
        ptr->next=ptr->next->next;
        free(temp);
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
void main()
{
    int item,pos,choice;
    while(1)
    {
        printf("\n1. Insert at beginning");
        printf("\n2. Insert at end");
        printf("\n3. Insert at position");
        printf("\n4. Deletion at beginning");
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
                ins_beg(item);
                break;
            case 2:
                printf("\nEnter the element: ");
                scanf("%d",&item);
                ins_end(item);
                break;
            case 3:
                printf("\nEnter the element: ");
                scanf("%d",&item);
                printf("\nEnter the position: ");
                scanf("%d",&pos);
                ins_pos(item,pos);
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
                printf("\nWrong choice");
        }
    }
}