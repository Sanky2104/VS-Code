//Author: Sanskriti Gupta
//Date: 15 March 2022
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int key;
    int value;
    struct Node *next;
};
struct Node *start=NULL;
struct Node *create_node();
void insert_update(int key, int value);
int search(int key);
int delete(int key);
int length();
int isKeyExist(int key);
int main()
{
    int choice,k,v,item;
    while(1)
    {
        printf("\n1. Insert/Update");
        printf("\n2. Search");
        printf("\n3. Delete");
        printf("\n4. Length");
        printf("\n5. Does the key exist ??");
        printf("\n6. Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the key and value: ");
                scanf("%d%d",&k,&v);
                insert_update(k,v);
                break;
            case 2:
                printf("\nKey to be searched: ");
                scanf("%d",&k);
                item=search(k);
                if(item==-1)
                {
                    printf("\nEntered Key does not exist");
                }
                else
                {
                    printf("\nValue Associated with %d: %d",k,item);
                }
                break;
            case 3:
                printf("\nKey to be deleted: ");
                scanf("%d",&k);
                item=delete(k);
                printf("\nDeleted Item: %d",item);
                break;
            case 4:
                item=length();
                printf("\nLength: %d",item);
                break;
            case 5:
                printf("\nKey which need to be checked: ");
                scanf("%d",&k);
                item=isKeyExist(k);
                if(item==1)
                {
                    printf("\nKey exists");
                }
                else
                {
                    printf("\nKey does NOT exist");
                }
                break;
            case 6:
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
void insert_update(int key, int value)
{
    struct Node *new=create_node();
    new->key=key;
    new->value=value;
    if(start==NULL)
    {
        start=new;
        new->next=NULL;
    }
    else
    {
        int flag=0;
        struct Node *temp=start,*ptr=start;
        while(ptr!=NULL)
        {
            if(ptr->key==key)
            {
                flag=flag+1;
                ptr->value=value;
            }
            ptr=ptr->next;
        }
        if(flag==0)
        {
            while(temp->key<key)
            {
                temp=temp->next;
            }
            new->next=temp->next;
            temp->next=new;
            printf("\nInsertion Successful");
        }
    }
}
int search(int key)
{
    int flag=0;
    struct Node *temp=start,*ptr=start;
    while(temp!=NULL)
    {
        temp=temp->next;
        if(temp->key==key)
        {
            flag++;
        }
    }
    while(ptr->key!=key)
    {
        ptr=ptr->next;
    }
    if(flag==0)
    {
        return -1;
    }
    else
    {
        return ptr->value;
    }
}
int delete(int key)
{
    int flag=0;
    struct Node *temp=start,*ptr=start;
    while(temp!=NULL)
    {
        temp=temp->next;
        if(temp->key==key)
        {
            flag++;
        }
    }
    while(ptr->key!=key)
    {
        ptr=ptr->next;
    }
    if(flag==0)
    {
        return -1;
    }
    else
    {
        ptr->next=ptr->next->next;
        return ptr->value;
    }
}
int length()
{
    int count=0;
    struct Node *ptr=start;
    while(ptr!=NULL)
    {
        ptr=ptr->next;
        count++;
    }
    return count;
}
int isKeyExist(int key)
{
    int flag=0;
    struct Node *ptr=start;
    while(ptr!=NULL)
    {
        ptr=ptr->next;
        if(ptr->key==key)
        {
            flag++;
        }
    }
    if(flag!=0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}