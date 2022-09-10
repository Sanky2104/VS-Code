#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *start = NULL;
void ins_beg();
void ins_end();
void ins_pos(int item, int pos);
int del_beg();
int del_end();
int del_pos(int pos);
int count();
void sort();
void display();
void main()
{
    int choice, item, pos;
    while(1)
    {
        printf("\n1. Insert in beginning");
        printf("\n2. Insert at end");
        printf("\n3. Insert at position");
        printf("\n4. Delete at beginning");
        printf("\n5. Delete at end");
        printf("\n6. Delete at position");
        printf("\n7. Count");
        printf("\n8. Sort");
        printf("\n9. Display");
        printf("\n10. Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter an element: ");
                scanf("%d",&item);
                ins_beg(item);
                break;
            case 2:
                printf("\nEnter an element: ");
                scanf("%d",&item);
                ins_end(item);
                break;
            case 3:
                printf("\nEnter element and the position: ");
                scanf("%d%d",&item,&pos);
                ins_pos(item, pos);
                break;
            case 4:
                item = del_beg();
                printf("\nDeleted Item: %d",item);
                break;
            case 5:
                item = del_end();
                printf("\nDeleted Item: %d",item);
                break;
            case 6:
                printf("\nEnter the position: ");
                scanf("%d",&pos);
                item = del_pos(pos);
                printf("\nDeleted Item: %d",item);
                break;
            case 7:
                item = count();
                printf("\nNo. of elements: %d",item);
                break;
            case 8:
                sort();
                break;
            case 9:
                display();
                break;
            case 10:
                exit(0);
            default:
                printf("\nNo such choice !!!");
        }
    }
}
struct Node *create_node()
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    return temp;
}
void ins_beg(int item)
{
    struct Node *new = create_node();
    new->data = item;
    if(start==NULL)
    {
        start = new;
        new->next = NULL;
    }
    else
    {
        new->next = start;
        start = new;
    }
}
void ins_end(int item)
{
    struct Node *new = create_node();
    new->data = item;
    new->next = NULL;
    if(start==NULL)
    {
        start=new;
    }
    else
    {
        struct Node *ptr = start;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new;
    }
}
void ins_pos(int item, int pos)
{
    struct Node *new = create_node();
    new->data = item;
    if(start == NULL)
    {
        start = new;
        new->next = NULL;
    }
    else
    {
        struct Node *ptr=start;
        int p=1;
        while(p<pos-1)
        {
            ptr=ptr->next;
            p++;
        }
        new->next = ptr->next;
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
        struct Node *temp = start;
        start=start->next;
        free(temp);
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
        printf("\nUNDERLFOW");
    }
    else
    {
        int p=1;
        struct Node *ptr=start;
        while(p<=pos-1)
        {
            ptr=ptr->next;
            p++;
        }
        int i =ptr->next->data;
        struct Node *temp=ptr->next;
        ptr->next=ptr->next->next;
        free(temp);
        return i;
    }
}
int count()
{
    if(start==NULL)
    {
        return 0;
    }
    else
    {
        struct Node *ptr=start;
        int c=0;
        while(ptr!=NULL)
        {
            c++;
            ptr=ptr->next;
        }
        return c;
    }
}
void sort()
{
    int i,swapped;
    struct Node *ptr;
    struct Node *temp=NULL;
    do
    {
        swapped=0;
        ptr=start;
        while(ptr->next != temp)
        {
            if(ptr->data > ptr->next->data)
            {
                int j=ptr->data;
                ptr->data=ptr->next->data;
                ptr->next->data=j;
                swapped=1;
            }
            ptr=ptr->next;
        }
        temp=ptr;
    }
    while(swapped);
}
void display()
{
    if(start==NULL)
    {
        printf("\nNOTHING TO DISPLAY !!!");
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