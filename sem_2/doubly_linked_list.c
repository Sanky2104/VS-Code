//Author: Sanskriti Gupta
//Date: 5 March 2022
//Aim: To implement doubly linked list 
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next,*prev;
};
struct Node *start=NULL;
void insert_beg(int item);
void insert_pos(int item, int pos);
void insert_end(int item);
int delete_beg();
int delete_pos(int pos);
int delete_end();
int linear_search(int item);
void display();
struct Node * create_node();
int main()
{
    int item,choice,pos,del;
    while(1)
    {
        printf("\n1. To Insert at beginning ");
        printf("\n2. To Insert at position ");
        printf("\n3. To Insert at end ");
        printf("\n4. To Delete at beginning ");
        printf("\n5. To Delete at position ");
        printf("\n6. To Delete at end ");
        printf("\n7. To Display ");
        printf("\n8. Linear Search");
        printf("\n9. To Exit \n");
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
                del=delete_beg();
                printf("\nDeleted Item: %d",del);
                break;
            case 5:
                printf("\nEnter the position: ");
                scanf("%d",&pos);
                del=delete_pos(pos);
                printf("\nDeleted item: %d",del);
                break;
            case 6:
                del=delete_end();
                printf("\nDeleted Item: %d",del);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("\nEnter element to be searched: ");
                scanf("%d",&item);
                int i=linear_search(item);
                if(i)
                {
                    printf("\n%d Found",item);
                }
                else
                {
                    printf("%d NOT found",item);
                }
                break;
            case 9:
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
        new->prev=start;
        start=new;
        new->next=NULL;
    }
    else
    {
        new->prev=start;
        new->next=start;
        start=new;
    }
}
void insert_pos(int item, int pos)
{
    struct Node *new=create_node();
    struct Node *ptr=start;
    int p=1;
    new->data=item;
    if(start==NULL)
    {
        new->next=NULL;
        new->prev=start;
        start=new;
    }
    else
    {
        while(p<pos-1)    
        {
            ptr=ptr->next;
            p++;
        }
        new->next=ptr->next;
        ptr->next->prev=new;
        ptr->next=new;
        ptr=new;
    }
}
void insert_end(int item)
{
    struct Node *new=create_node();
    struct Node *ptr=start;
    new->data=item;
    if(start==NULL)
    {
        new->prev=NULL;
        new->next=NULL;
        start=new;
    }
    else
    {
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=new;
        new->prev=ptr;
        new->next=NULL;
    }
}
int delete_beg()
{
    int i;
    if(start==NULL)
    {
        printf("\nEmpty List");
        return -1;
    }
    else if(start->next==NULL)
    {
        i=start->data;
        struct Node *temp=start;
        start=NULL;
        free(temp);
    }
    else
    {
        i=start->data;
        start->next->prev=start;
        start=start->next;
    }
    return i;
}
int delete_end()
{
    int i;
    struct Node *ptr=start;
    if(start==NULL)
    {
        printf("\nEmpty List");
        return -1;
    }
    else if(start->next==NULL)
    {
        i=start->data;
        struct Node *temp=start;
        start=NULL;
        free(temp);
    }
    else
    {
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        i=ptr->data;
        ptr->prev->next=NULL;
        free(ptr);
    }
    return i;
}
int delete_pos(int pos)
{
    struct Node *ptr=start;
    int i,p=1;
    if(start==NULL)
    {
        printf("\nList is Empty");
    }
    else
    {
        while(p<pos)
        {
            ptr=ptr->next;
            p++;
        }
        i=ptr->data;
        struct node *temp=ptr;
        ptr->prev->next=ptr->next;
        ptr->next->prev=ptr->prev;
        free(temp);
        return i;
    }
}
int linear_search(int item)
{
    int flag=0;
    if(start->data==item)
    {
        flag++;
    }
    else
    {
        struct Node *ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
            if(ptr->data==item)
            {
                flag++;
                break;
            }
        }
    }
    return flag;
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