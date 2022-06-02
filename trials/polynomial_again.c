//Author: Sanskriti Gupta
//Date: 27 April 2022
//Aim: To add 2 polynomials using linked list

//YE WALA SAHI HAI, LEKIN MERA NAHI HAI 

#include<stdio.h>
#include<stdlib.h>
struct Node
{
    float coeff;
    int expo;
    struct Node *link;
};
struct Node *insert(struct Node *head, float  co, int ex)
{
    struct Node *temp;
    struct Node *newp=(struct Node *)malloc(sizeof(struct Node));
    newp->coeff=co;
    newp->expo=ex;
    newp->link=NULL;
    if(head==NULL || ex > head->expo)
    {
        newp->link=head;
        head=newp;
    }
    else
    {
        temp=head;
        while(temp->link!=NULL && temp->link->expo >= ex)
        {
            temp=temp->link;
        }
        newp->link=temp->link;
        temp->link=newp;
    }
    return head;
}
struct Node *create(struct Node *head)
{
    int n,i;
    float coeff;
    int expo;
    printf("\nEnter the number of terms: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter co-efficent for term %d: ",i+1);
        scanf("%f",&coeff);
        printf("\nEnter exponent for term %d: ",i+1);
        scanf("%d",&expo);
        head=insert(head,coeff,expo);
    }
    return head;
}
void print(struct Node *head)
{
    if(head==NULL)
    {
        printf("\nNo polynomial");
    }
    else
    {
        struct Node *temp=head;
        while(temp!=NULL)
        {
            printf("(%.1fx^%d)",temp->coeff,temp->expo);
            temp=temp->link;
            if(temp!=NULL)
            {
                printf(" + ");
            }
            else
            {
                printf("\n");
            }
        }
    }
}
void polyadd(struct Node *head1, struct Node *head2)
{
    struct Node *ptr1=head1;
    struct Node *ptr2=head2;
    struct Node *head3=NULL;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->expo==ptr2->expo)
        {
            head3=insert(head3,ptr1->coeff+ptr2->coeff,ptr1->expo);
            ptr1=ptr1->link;
            ptr2=ptr2->link;
        }
        else if(ptr1->expo > ptr2->expo)
        {
            head3=insert(head3,ptr1->coeff,ptr1->expo);
            ptr1=ptr1->link;
        }
        else if(ptr1->expo < ptr2->expo)
        {
            head3=insert(head3,ptr2->coeff,ptr2->expo);
            ptr2=ptr2->link;
        }
    }
    while(ptr1!=NULL)
    {
        head3=insert(head3,ptr1->coeff,ptr1->expo);
        ptr1=ptr1->link;
    }
    while(ptr2!=NULL)
    {
        head3=insert(head3,ptr2->coeff,ptr2->expo);
        ptr2=ptr2->link;
    }
    printf("\nAdded polynomial is: ");
    print(head3);
}
void main()
{
    struct Node *head1=NULL,*head2=NULL;
    printf("\nEnter the first polynomial: ");
    head1=create(head1);
    printf("\nEnter the second polynomial: ");
    head2=create(head2);
    polyadd(head1,head2);
}