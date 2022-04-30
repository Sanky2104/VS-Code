//Author: Sanskriti Gupta
//Date: 14 April 2022
//Aim: To implement stack and its operations
#include<stdio.h>
#include<stdlib.h>
#define capacity 100
int top=-1;
int stack[capacity];
void push(int item)
{
    if(top==capacity)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        top++;
        stack[top]=item;
    }
}
int pop()
{
    if(top==-1)
    {
        printf("\nUNDERFLOW");
    }
    else
    {
        int i=stack[top];
        top--;
        return i;
    }
}
void display()
{
    if(top==-1)
    {
        printf("\nSTACK EMPTY");
    }
    else
    {
        for(int i=top;i>=0;i--)
        {
            printf("%d->",stack[i]);
        }
    }
}
int peek()
{
    if(top==-1)
    {
        printf("\nEMPTY STACK");
    }
    else
    {
        return stack[top];
    }
}
void main()
{
    int choice, item;
    while(1)
    {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Peek");
        printf("\n5. Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter element: ");
                scanf("%d",&item);
                push(item);
                break;
            case 2:
                item=pop();
                printf("\nDeleted Item: %d",item);
                break;
            case 3:
                display();
                break;
            case 4:
                item=peek();
                printf("\nTopmost Item: %d",item);
                break;
            case 5:
                exit(0);
            default:
                printf("\nWrong Choice");
        }
    }
}