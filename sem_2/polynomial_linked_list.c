#include<stdio.h>
#include<stdlib.h>
struct Node
{
    float coeff;
    int expo;
    struct Node *link;
};
struct Node *create(struct Node *);
struct Node *insert_s(struct Node *, float ,int);
struct Node *insert(struct Node *, float, int);
void display(struct Node *ptr);
void poly_add(struct Node *, struct Node *);
int main()
{
    struct Node *start1=NULL,*start2=NULL;
    printf("Enter polynimial 1: \n");
    start1=create(start1);
    printf("Enter polynomial 2: \n");
    start2=create(start2);
    printf("Polynomial 1 is: ");
    display(start1);
    printf("Polynomial 2 is: ");
    display(start2);
    poly_add(start1,start2);
    return 0;
}
struct Node *create(struct Node *start)
{
    int i,n,ex;
    float co;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Enter coefficient for term %d: ",i);
        scanf("%f",&co);
        printf("Enter exponent for term %d: ",i);
        scanf("%d",&ex);
        start=insert_s(start,co,ex);
    }
    return start;
}
struct Node *insert_s(struct Node *start, float co, int ex)
{
    struct Node *ptr,*tmp;
    tmp=(struct Node *)malloc(sizeof(struct Node));
    tmp->coeff=co;
    tmp->expo=ex;
    if(start==NULL || ex>start->expo)
    {
        tmp->link=start;
        start=tmp;
    }
    else
    {
        ptr=start;
        while(ptr->link!=NULL && ptr->link->expo>=ex)
        {
            ptr=ptr->link;
            tmp->link=ptr->link;
            ptr->link=NULL;
        }
    }
    return start;
}
struct Node *insert(struct Node *start, float co, int ex)
{
    struct Node *ptr,*tmp;
    tmp=(struct Node *)malloc(sizeof(struct Node));
    tmp->coeff=co;
    tmp->expo=ex;
    if(start==NULL)
    {
        tmp->link=start;
        start=tmp;
    }
    else
    {
        ptr=start;
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        tmp->link=ptr->link;
        ptr->link=tmp;
    }
    return start;
}
void display(struct Node *ptr)
{
    if(ptr==NULL)
    {
        printf("Zero Polynomial\n");
        return ;
    }
    while(ptr!=NULL)
    {
        printf("%.1fx^%d",ptr->coeff,ptr->expo);
        ptr=ptr->link;
        if(ptr!=NULL)
        {
            printf(" + ");
        }
        else
        {
            printf("\n");
        }
    }
}
void poly_add(struct Node *p1,struct Node *p2)
{
    struct Node *start3;
    start3=NULL;
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->expo > p2->expo)
        {
            start3=insert(start3,p1->coeff,p1->expo);
            p1=p1->link;
        }
        else if(p2->expo > p1->expo)
        {
            start3=insert(start3,p2->coeff,p2->expo);
            p2=p2->link;
        }
        else if(p1->expo==p2->expo)
        {
            start3=insert(start3,p1->coeff + p2->coeff,p1->expo);
            p1=p1->link;
            p2=p2->link;
        }
    }
    while(p1!=NULL)
    {
        start3=insert(start3,p1->coeff,p1->expo);
        p1=p1->link;
    }
    while(p2!=NULL)
    {
        start3=insert(start3,p2->coeff,p2->expo);
        p2=p2->link;
    }
    printf("Added polynomial is: ");
    display(start3);
}