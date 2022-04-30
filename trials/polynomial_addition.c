//Author: Sanskriti Gupta
//Date: 27 April 2022
//Aim: To add 2 polynomials using linked list
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int co_eff;
    int expo;
    struct Node *next;
};
struct Node *start1=NULL;
struct Node *start2=NULL;
struct Node *start3=NULL;
struct Node *create_node()
{
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    return temp;
}
void ins_poly(struct Node *start, int value, int exp)
{
    struct Node *new=create_node();
    new->co_eff=value;
    new->expo=exp;
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
void add()
{
    struct Node *ptr1=start1, *ptr2=start2;
    struct Node *new=create_node();
    while(ptr1!=NULL || ptr2!=NULL)
    {
        if(start3==NULL)
        {
            start3=new;
            new->next=NULL;
        }
        else
        {
            struct Node *ptr=start3;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=new;
            new->next=NULL;
        }
        if(ptr1->expo==ptr2->expo)
        {
            new->co_eff=ptr1->co_eff+ptr2->co_eff;
            new->expo=ptr1->expo;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        else if(ptr1->expo > ptr2->expo)
        {
            new->expo=ptr1->expo;
            new->co_eff=ptr1->co_eff;
            ptr1=ptr1->next;
        }
        else
        {
            new->expo=ptr2->expo;
            new->co_eff=ptr2->co_eff;
            ptr2=ptr2->next;
        }
    }
}
void display(struct Node *start)
{
    struct Node *ptr=start;
    printf("\n");
    while(ptr->next!=NULL)
    {
        printf("%d",ptr->co_eff);
        printf("x%d + ",ptr->expo);
        ptr=ptr->next;
    }
}
void main()
{
    int value,exp,choice;
    while(1)
    {
        printf("\n1. Create polynomial 1");
        printf("\n2. Create polynomial 2");
        printf("\n3. Add");
        printf("\n4. Display polynomial 1");
        printf("\n5. Display polynomial 2");
        printf("\n6. Display added polynomial");
        printf("\n7. Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the exponent: ");
                scanf("%d",&exp);
                printf("\nEnter the co-efficient: ");
                scanf("%d",&value);
                ins_poly(start1,value,exp);
                break;
            case 2:
                printf("\nEnter the exponent: ");
                scanf("%d",&exp);
                printf("\nEnter the co-efficient: ");
                scanf("%d",&value);
                ins_poly(start2,value,exp);
                break;
            case 3:
                add();
                break;
            case 4:
                display(start1);
                break;
            case 5:
                display(start2);
                break;
            case 6:
                display(start3);
                break;
            case 7:
                exit(0);
            default:
                printf("\nWrong Choice");
        }
    }
}