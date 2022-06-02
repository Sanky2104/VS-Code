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
        new->prev=NULL;
        start=new;
    }
}
void ins_end(int item)
{
    struct Node *new=create_node();
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
        ptr->next=new;
        new->prev=ptr;
        new->next=NULL;
    }
}
void ins_pos(int item, int pos);
int del_beg();
int del_end();
int del_pos(int pos);
void display()
{
    if(start==NULL)
    {
        printf("\nNothing to Print, Empty List");
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
void display_reverse()
{
    if(start==NULL)
    {
        printf("\nEmpty list");
    }
    else
    {
        struct Node *ptr=start;
        while(ptr!=NULL)
        {
            ptr=ptr->next;
        }
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->prev;
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
        printf("\n8. Display in reverse");
        printf("\n9. Exit\n");
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
                sacnf("%d",&pos);
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
                display_reverse();
                break;
            case 9:
                exit(0);
            default:
                printf("\nWrong Choice");
        }
    }
}