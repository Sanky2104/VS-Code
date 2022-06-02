//Author: Sanskriti Gupta
//Date: 1 May 2022
//Aim: To implement singly linked list

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
void ins_beg(int item)
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
void ins_end(int item)
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
void ins_pos(int item, int pos)
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
int del_beg()
{
    if(start==NULL)
    {
        printf("\nUNDERFLOW");
    }
    else
    {
        int i=start->data;
        struct Node *temp=start;
        start=start->next;
        free(temp);;
        return i;
    }
}
int del_end()
{
    if(start==NULL)
    {
        printf("\nUNDERFLOW");
    }
    else
    {
        struct Node *ptr=start;
        while(ptr->next->next!=NULL)
        {
            ptr=ptr->next;
        }
        struct Node *temp=ptr->next;
        int i=ptr->next->data;
        ptr->next=NULL;
        free(temp);
        return i;
    }
}
int del_pos(int pos)
{
    if(start==NULL)
    {
        printf("\nUNDERFLOW");
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
        int i=ptr->next->data;
        struct Node *temp=ptr->next;
        ptr->next=ptr->next->next;
        free(temp);
        return i;
    }
}
void display()
{
    if(start==NULL)
    {
        printf("\nEmpty List, Nothing to print !!!");
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
    int choice,item,pos;
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
                printf("\nWrong Choice");
        }
    }
}