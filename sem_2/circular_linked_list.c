//Author: Sanskriti Gupta
//Aim: Implement circular linked list and its operations
#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int info;
	struct Node *link;
};
struct Node *create_list(struct Node *last);
void display(struct Node *last);
struct Node *add_to_empty(struct Node *last, int data);
struct Node *add_to_beg(struct Node *last, int data);
struct Node *add_at_end(struct Node *last, int data);
struct Node *add_after(struct Node *last, int data, int item);
struct Node *del(struct Node *last, int data);
int main()
{
    int choice, data, item;
    struct Node *last=NULL;
    while(1)
    {
        printf("1. Create List\n");
        printf("2. Display\n");
        printf("3. Add to empty\n");
        printf("4. Add at beginning\n");
        printf("5. Add at end\n");
        printf("6. Add after\n");
        printf("7. Delete\n");
        printf("8. Quit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                last=create_list(last);
                break;
            case 2:
                display(last);
                break;
            case 3:
                printf("Enter element to be inserted: ");
                scanf("%d",&data);
                last=add_to_empty(last,data);
                break;
            case 4:
                printf("Enter element to be inserted: ");
                scanf("%d",&data);
                last=add_at_end(last,data);
                break;
            case 5:
                printf("Enter element to be inserted: ");
                scanf("%d",&data);
                last=add_at_end(last,data);
                break;
            case 6:
                printf("Enter element to be inserted: ");
                scanf("%d",&data);
                printf("Enter element after  which to insert: ");
                scanf("%d",&item);
                last=add_after(last,data,item);
                break;
            case 7:
                printf("Enter element to be deleted: ");
                scanf("%d",&data);
                last=del(last,data);
                break;
            case 8:
                exit(1);
            default:
                printf("\nWrong Choice\n");
        }
    }
}
void display(struct Node *last)
{
    struct Node *p;
    if(last==NULL)
    {
        printf("\nList is Empty\n");
        return ;
    }
    p=last->link;
    do
    {
        printf("%d ",p->info);
        p=p->link;
    }
    while(p!=last->link);
    printf("\n");
}
struct Node *add_to_beg(struct Node *last, int data)
{
    struct Node *tmp;
    tmp=(struct Node *)malloc(sizeof(struct Node));
    tmp->info=data;
    tmp->link=last->link;
    last->link=tmp;
    return last;
}
struct Node *add_to_empty(struct Node *last, int data)
{
    struct Node *tmp;
    tmp=(struct Node *)malloc(sizeof(struct Node));
    tmp->info=data;
    last=tmp;
    last->link=last;
    return last;
}
struct Node *add_at_end(struct Node *last, int data)
{
    struct Node *tmp;
    tmp=(struct Node *)malloc(sizeof(struct Node));
    tmp->info=data;
    tmp->link=last->link;
    last->link=tmp;
    last=tmp;
    return last;
}
struct Node *add_after(struct Node *last, int data, int item)
{
    struct  Node *tmp,*p;
    p=last->link;
    do
    {
        if(p->info==item)
        {
            tmp=(struct Node *)malloc(sizeof(struct Node));
            tmp->info=data;
            tmp->link=p->link;
            p->link=tmp;
            if(p==last)
            {
                last=tmp;
                return last;
            }
            p=p->link;
        }
    }
    while(p!=last->link);
    printf("\n%d not present in list\n",item);
    return last;
}
struct Node *create_list(struct Node *last)
{
    int i,n,data;
    printf("Enter the no. of nodes: ");
    scanf("%d",&n);
    last=NULL;
    if(n==0)
    {
        return last;
    }
    printf("Enter element to be inserted: ");
    scanf("%d",&data);
    last=add_to_empty(last,data);
    for(i=2;i<=n;i++)
    {
        printf("Enter element to be inserted: ");
        scanf("%d",&data);
        last=add_at_end(last,data);
    }
    return last;
}
struct Node *del(struct Node *last, int data)
{
    struct Node *tmp,*p;
    if(last==NULL)
    {
        printf("List is Empty\n");
        return last;
    }
    if(last->link==last && last->info==data)
    {
        tmp=last;
        last=NULL;
        free(tmp);
        return last;
    }
    if(last->link->info==data)
    {
        tmp=last->link;
        last->link=tmp->link;
        free(tmp);
        return last;
    }
    p=last->link;
    while(p->link!=last)
    {
        if(p->link->info==data)
        {
            tmp=p->link;
            p->link=tmp->link;
            free(tmp);
            return last;
        }
        p=p->link;
    }
    if(last->info==data)
    {
        tmp=last;
        p->link=last->link;
        last=p;
        free(tmp);
        return last;
    }
    printf("Element %d not found\n",data);
    return last;
}