//Author: Sanskriti Gupta
//Date: 10 March 2022
//Aim: To implement insertion/deletion at beginning, end and position of a singly linked list
#include<stdlib.h>
#include <stdio.h>
struct Node 
{
	int data;
	struct Node *link;
};
struct Node *start=NULL;
void display();
struct Node *create_node();
void ins_beg(int item);
void ins_end(int item);
void ins_pos(int item, int pos);
int del_beg();
int del_end();
int del_pos(int pos);
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
    struct Node *new=create_node();
    struct Node *ptr=start;
    new->data=item;
    if(pos==0)
    {
        new->link=start;
        start=new;
    }
    else
    {
        for(int i=0;i<pos;i++)
        {
            ptr=ptr->link;
            if(ptr==NULL)
            {
                printf("\nPosition not found");
            }
        }
        new->link=ptr->link;
        ptr->link=new;
    }
}
int del_beg()
{
    int d;
    struct Node *del;
    if(start==NULL)
    {
        printf("\nUnderflow");
        return 0;
    }
    else
    {
        del=start;
        start=start->link;
        d=del->data;
        free(del);
    }
    return d;
}
int del_end()
{
    int d;
    struct Node *ptr,*ptr1;
    if(start==NULL)
    {
        printf("\nUnderflow");
        return 0;
    }
    else
    {
        ptr=start;
        while(ptr->link!=NULL)
        {
            ptr1=ptr;
            ptr=ptr->link;
        }
        ptr1->link=NULL;
        d=ptr->data;
        free(ptr);
        return d;
    }
}
int del_pos(int pos)
{
    struct Node *temp,*ptr;
    int i,d;
    if(start==NULL)
    {
        printf("\nUnderflow");
        return 0;
    }
    else
    {
        if(pos==0)
        {
            ptr=start;
            start=start->link;
            d=ptr->data;
            free(ptr);
            return d;
        }
        else
        {
            ptr=start;
            for(i=0;i<pos;i++)
            {
                temp=ptr;
                ptr=ptr->link;
                if(ptr==NULL)
                {
                    printf("\nPosition not found");
                    return 0;
                }
            }
            temp->link=ptr->link;
            d=ptr->data;
            free(ptr);
            return d;
        }
    }
}
void display()
{
    while(start!=NULL)
    {
        printf("%d ",start->data);
        start=start->link;
    }
}