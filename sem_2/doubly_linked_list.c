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
        printf("\n8. To Exit \n");
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
    
}
void insert_end(int item)
{

}
int delete_beg()
{

}
int delete_end()
{

}
int delete_pos(int pos)
{

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