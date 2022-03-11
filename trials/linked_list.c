//Author: Sanskriti Gupta
//Date: 10 March 2022
//Aim: To implement insertion/deletion at beginning, end and position of a singly linked list
#include<stdlib.h>
#include <stdio.h>
struct Node 
{
	int data;
	struct Node *next;
};
void display(struct Node *start) //printing the list 
{
    printf("Current List Is:\n");
	while(start != NULL)
	{
		printf("%d ",start->data);
		start = start->next;
	}
	printf("\n");
} 
//using pointer to pointer as call by refrence
void insert_begin(struct Node **start, int item) //inserting element in the begining 
{
    struct Node *new;
    new=(struct Node *)malloc(sizeof(struct Node));
    if(new==NULL)
    {
        printf("Empty list \n");
        return;
    }
    new->data=item;
    if(*start==NULL)
    {
        *start=new;
    }
    else
    {
        new->next=*start;
        *start=new;
    }
}
void insert_end(struct Node **start, int item)//inserting at the end
{
    struct Node* new,*ptr;
    new= (struct Node *)malloc(sizeof(struct Node));
    if(new==NULL)
    {
        printf("No memory space \n");
        return;
    }
    new->next=NULL;
    if(*start==NULL)
    {
        *start==new;
    }
    else
    {
      ptr=*start;
      while(ptr->next!=NULL)
      {
          ptr=ptr->next;
      }
    ptr->next=new;
    return;
    }
}
void insert_pos(struct Node **start, int item, int pos)//inserting at a position
{
    struct Node *new,*ptr;
    new=(struct Node *)malloc(sizeof(struct Node));
    int i;
    if(new==NULL)
    {
        printf("No memory space \n");
        return;
    }
    new->data=item;
    new->next=NULL;
    if(pos==0)
    {
        new->next=*start;
        *start=new;
    }
    else
    {
        for(i=0;i<pos;i++)
        {
            ptr=ptr->next;
            if(ptr==NULL)
            {
                printf("Position not found \n");
                return;
            }
        }
        new->next=ptr->next;
        ptr->next=new;
    }
}
int delete_begin(struct Node **start)//deleting from the begining
{ int d;
    struct Node *del;
    if(*start==NULL)
    {
        printf("The list is empty \n");
        return 0;
    }
    else
    {
        del=*start;
        *start=(*start)->next;
        d= del->data;
        free(del);
    }
    return(d);
}
int delete_end(struct Node **start)//deleting from the end
{ int d;
    struct Node *ptr,*temp;
    if(*start==NULL)
    {
        printf("The list is empty \n");
        return 0;
    }
    else
    {
        ptr=*start;
        while(ptr->next !=NULL)
        {
            temp=ptr;
            ptr=ptr->next;
        }
        temp->next=NULL;
        d=ptr->data;
        free(ptr);
        return(d);
    }
}
int delete_pos(struct Node **start, int pos)// deleting from a given position
{
    struct Node *temp,*ptr;
    int i,d;
    if(*start==NULL)
    {
        printf("The list is empty \n");
        return 0;
    }
    else
    {
        if(pos==0)
        {
            ptr=*start;
            *start=(*start)->next;
            d=ptr->data;
            free(ptr);
            return (d);
        }
        else
        {
            ptr=*start;
            for(i=0;i<pos;i++)
            {
                temp=ptr;
                ptr=ptr->next;
                if(ptr==NULL)
                {
                    printf("Position not found \n");
                    return 0;
                }
            }
            temp->next=ptr->next;
            d=ptr->data;
            free(ptr);
            return(d);
            }
        }
    }

int main()
{
	struct Node *Head=NULL;
	int choice, item, deleted_item, pos;
	while(1){
	printf("\n1. To Insert at beginning");
	printf("\n2. To insert at end");
    printf("\n3. To insert at position");
    printf("\n4. To delete at beginning");
    printf("\n5. To delete at end");
    printf("\n6. To delete at position");
    printf("\n7. To Display");
    printf("\n8. To exit\n");
    scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("\nEnter the element: ");
			scanf("%d", &item);
			insert_begin(&Head, item);
			break;

		case 2:
			printf("\nEnter the element: ");
			scanf("%d", &item);
			insert_end(&Head, item);
			break;

		case 3:
			printf("\nEnter the element: ");
			scanf("%d", &item);
			printf("\nEnter the position: ");
			scanf("%d", &pos);
			insert_begin(&Head, item);
			break;

		case 4:
			deleted_item = delete_begin(&Head);
			printf("\nDeleted Item: %d",deleted_item);
			break;

		case 5:
			delete_end(&Head);
			printf("\nDeleted Item: %d",deleted_item);
			break;

		case 6:
			printf("\nEnter position at which you want to delete\n");
			scanf("%d", &pos);
			delete_pos(&Head, pos);
			printf("\nDeleted Item: %d\n",deleted_item);
			break;

		case 7:
			display(Head);
			break;
		case 8:
			exit(0);
		default:
			printf("\nWrong Choice");
	}
	}
}