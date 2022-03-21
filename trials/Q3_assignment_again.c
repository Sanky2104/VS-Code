//Author: Sanskriti Gupta
//Date:16 March 2022
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct DATA
    {
        int key;
        int value;
    } *data;
    struct Node *next;
};
struct Node *start=NULL;
struct Node *create_node();
void insert_update(int key, int value);
int search(int key);
int delete(int key);
int length();
int isKeyExist(int key);
void display();
int main()
{
    int choice,key,value;
    while(1)
    {
        printf("\n1. Insert/Update");
        printf("\n2. Search");
        printf("\n3. Delete");
        printf("\n4. Find length");
        printf("\n5. Does your key exist ?");
        printf("\n6. Display");
        printf("\n7. Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the key: ");
                scanf("%d",&key);
                printf("\nEnter the value: ");
                scanf("%d",&value);
                insert_update(key,value);
                break;
            case 2:
                printf("\nKey to Search: ");
                scanf("%d",&key);
                value=search(key);
                if(value==-1)
                {
                    printf("\n%d",value);
                }
                else
                {
                    printf("Value associated with %d: %d",key,value);
                }
                break;
            case 3:
                printf("\nEnter key to delete: ");
                scanf("%d",&key);
                value=delete(key);
                if(value==-1)
                {
                    printf("\n%d",value);
                }
                else
                {
                    printf("\nDeleted Item: %d",value);
                }
                break;
            case 4:
                value=length();
                printf("\nLength of the list: %d\n",value);
                break;
            case 5:
                printf("\nKey to find: ");
                scanf("%d",&key);
                value=isKeyExist(key);
                if(value==0)
                {
                    printf("\nNo such key");
                }
                else
                {
                    printf("\nKey exists");
                }
                break;
            case 6:
                display();
                break;
            case 7:
                exit(0);
            default:
                printf("\nWrong Choice");
        }
    }
    return 0;
}
struct Node *create_node()
{
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    return temp;
}
void insert_update(int key, int value)
{
    struct Node *ptr=start;
    struct Node *new=create_node();
    new->data->key=key;
    new->data->value=value;
    if(start==NULL)
    {
        new->next=NULL;
        start=new;
    }
    else
    {
        while(ptr->data->key<key)
        {
            ptr=ptr->next;
        }
        new->next=ptr->next;
        ptr->next=new;
    }
}
int search(int key)
{
    int i=-1;
    struct Node *ptr=start;
    while(ptr->next!=NULL)
    {
        if(ptr->data->key==key)
        {
            i=ptr->data->value;
            break;
        }
        ptr=ptr->next;
    }
    if(i==-1)
    {
        return -1;
    }
    else
    {
        return i;
    }
}
int delete(int key)
{
    struct Node *ptr=start,*temp;
    int i,flag=0;
    while(ptr->data->key<=key)
    {
        if(ptr->data->key==key)
        {
            temp=ptr->next;
            i=ptr->data->value;
            ptr->next=ptr->next->next;
            free(temp);
            ++flag;
            break;
        }
        ptr=ptr->next;
    }
    if(flag==0)
    {
        return -1;
    }
    else
    {
        return i;
    }
}
int length()
{
    struct Node *ptr=start;
    int count=1;
    while(ptr->next!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    return count;
}
int isKeyExist(int key)
{
    struct Node *ptr=start;
    int flag=0;
    while(ptr!=NULL)
    {
        if(ptr->data->key==key)
        {
            flag++;
            break;
        }
        ptr=ptr->next;
    }
    if(flag==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void display()
{
    struct Node *ptr=start;
    while(ptr!=NULL)
    {
        printf("%d:%d ",ptr->data->key,ptr->data->value);
        ptr=ptr->next;
    }
}