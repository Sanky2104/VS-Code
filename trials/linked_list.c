//Author: Sanskriti Gupta
//Date: 10 March 2022
//Aim: To implement insertion/deletion at beginning, end and position of a singly linked list

//YE WALA SAHI HAI !!!!!

#include<stdlib.h>
#include <stdio.h>
struct Node 
{
	int data;
	struct Node *link;
};
struct Node *start=NULL;
void display()
{
    struct Node *ptr=start;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
}
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
        new->link=NULL;
    }
    else
    {
        new->link=start;
        start=new;
    }
}
void ins_end(int item)
{
    struct Node *new=create_node();
    new->data=item;
    new->link=NULL;
    if(start==NULL)
    {
        start=new;
    }
    else
    {
        struct Node *ptr=start;
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=new;
    }
}
void ins_pos(int item, int pos)
{
    int p=1;
    struct Node *new=create_node();
    new->data=item;
    if(start==NULL)
    {
        start=new;
        new->link=NULL;
    }
    else
    {
        struct Node *ptr=start;
        while(p<pos-1)
        {
            ptr=ptr->link;
            p++;
        }
        new->link=ptr->link;
        ptr->link=new;
    }
}
int del_beg()
{
    if(start==NULL)
    {
        printf("\nEmpty List");
    }
    else
    {
        int i=start->data;
        start=start->link;
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
        while(ptr->link->link!=NULL)
        {
            ptr=ptr->link;
        }
        int i=ptr->link->data;
        struct Node *temp=ptr->link;
        ptr->link=NULL;
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
            ptr=ptr->link;
            p++;
        }
        int i=ptr->link->data;
        struct Node *temp=ptr->link;
        ptr->link=ptr->link->link;
        free(temp);
        return i;
    }
}
void main()
{
    int item,pos,choice;
    while(1)
    {
        printf("\n1. Insert at bginning");
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