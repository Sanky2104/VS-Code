#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int info;
    struct Node *link;
};
struct Node *create_node(struct Node *start);
void display(struct Node *start);
struct Node* insert_begin(struct Node *start, int data);
struct Node* insert_end(struct Node *start, int data);
struct Node *insert_pos(struct Node *start, int data, int pos);
struct Node *create_node(struct Node *start)
{
    int i,n,data;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    start=NULL;
    if(n==0)
    {
        return start;
    }
    printf("Enter the element to be inserted: ");
    scanf("%d",&data);
    start=insert_begin(start,data);
    for(i=2;i<=n;i++)
    {
        printf("Enter the element to be inserted: ");
        scanf("%d",&data);
        start=insert_end(start,data);
    }
    return start;
}
void display(struct Node *start)
{
    struct Node *p;
    if(start==NULL)
    {
        printf("EMPTY LIST\n");
        return;
    }
    p=start;
    printf("List is: ");
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p=p->link;
    }
    printf("\n\n");
}
struct Node* insert_begin(struct Node *start, int data)
{
    struct Node *tmp;
    tmp=(struct Node *)malloc(sizeof(struct Node));
    tmp->info=data;
    tmp->link=start;
    start=tmp;
    return start;
}
struct Node* insert_end(struct Node *start, int data)
{
    struct Node *p,*tmp;
    tmp=(struct Node *)malloc(sizeof(struct Node));
    tmp->info=data;
    p=start;
    while(p->link!=NULL)
    {
        p=p->link;
    }
    p->link=tmp;
    tmp->link=NULL;
    return start;
}
struct Node *insert_pos(struct Node *start, int data, int pos)
{
    struct Node *tmp,*p;
    int i;
    tmp=(struct Node *)malloc(sizeof(struct Node));
    tmp->info=data;
    if(pos==1)
    {
        tmp->link=start;
        start=tmp;
        return start;
    }
    p=start;
    for(i=1;i<pos-1 && p!=NULL;i++)
    {
        p=p->link;
    }
    if(p==NULL)
    {
        printf("There are less than %d elements\n",pos);
    }
    else
    {
        tmp->link=p->link;
        p->link=tmp;
    }
    return start;
}
int main()
{
    struct Node *start=NULL;
    int choice, data, item, pos;
    while(1)
    {
        printf("1. Create List\n");
        printf("2. Display\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at end\n");
        printf("5. Insert at Pos\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    start=create_node(start);
                    break;
            case 2:
                    display(start);
                    break;
            case 3:
                    printf("Enter element to be inserted: ");
                    scanf("%d",&data);
                    start=insert_begin(start,data);
                    break;
            case 4:
                    printf("Enter element to be inserted: ");
                    scanf("%d",&data);
                    start=insert_end(start,data);
                    break;
            case 5:
                    printf("Enter element to be inserted: ");
                    scanf("%d",&data);
                    start=insert_pos(start,data,pos);
                    break;
            case 6:
                    exit(1);
            default:
                    printf("Wrong Choice\n");
        }
    }
    return 0;
}