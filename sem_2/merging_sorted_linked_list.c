#include<stdlib.h>
#include<stdio.h>
struct LinkedList //Structure created
{
    int data;
    struct LinkedList *Next;
};

void input(struct LinkedList **List , int len)
{
    struct LinkedList *New = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    printf("Enter a Number: ");
    scanf("%d" , &New->data);
    New->Next = NULL;
    *List = New;
    for(int i = 2 ; i <= len ; i++)
    {
        New->Next = (struct LinkedList *)malloc(sizeof(struct LinkedList));
        New = New->Next;
        printf("Enter a Number: ");
        scanf("%d" , &New->data);
        New->Next = NULL;
    }
}

void Display(struct LinkedList *List) //function to display the list
{
    struct LinkedList *temp = List;
    while(temp != NULL)
    {
        printf("%d\t" , temp->data);
        temp = temp->Next;
    }
}

void Merge(struct LinkedList *List1 , struct LinkedList *List2 , struct LinkedList **ResList) //function to merge the lists
{
    struct LinkedList *New = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    New->Next = NULL;
    *ResList = New;
    
    while(List1 != NULL && List2 != NULL)
    {
        if(List1->data > List2->data)
        {
            New->data = List2->data;
            List2 = List2->Next;
        }
        
        else if(List1->data < List2->data)
        {
            New->data = List1->data;
            List1 = List1->Next;
        }
        
        else
        {
            New->data = List1->data;
            List1 = List1->Next;
            List2 = List2->Next;
        }
        
        if(List1 && List2)
        {
            New->Next = (struct LinkedList *)malloc(sizeof(struct LinkedList));
            New = New->Next;
            New->Next = NULL;
        }
    }
    
    while(List1 != NULL)
    {
        New->Next = (struct LinkedList *)malloc(sizeof(struct LinkedList));
        New = New->Next;
        New->Next = NULL;
        New->data = List1->data;
        List1 = List1->Next;
    }
    
    while(List2 != NULL)
    {
        New->Next = (struct LinkedList *)malloc(sizeof(struct LinkedList));
        New = New->Next;
        New->Next = NULL;
        New->data = List2->data;
        List2 = List2->Next;
    }
}

void main()
{
    struct LinkedList *List1 = NULL;
    struct LinkedList *List2 = NULL;
    struct LinkedList *ResList = NULL;
    printf("Enter the length of Two Lists\n");
    int len1 , len2;
    scanf("%d%d",&len1 ,&len2);
    printf("Enter %d elements of List 1 in Increasing Order\n" , len1);
    input(&List1,len1);
    printf("Enter %d elements of List 2 in Increasing Order\n" , len2);
    input(&List2,len2);
    printf("\nList 1 :-\n");
    Display(List1);
    printf("\nList 2 :-\n");
    Display(List2);
    Merge(List1 , List2 , &ResList);
    printf("\nResultant List :- \n");
    Display(ResList);
}
