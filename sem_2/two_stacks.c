//Author: Sanskriti Gupta
//Aim: Using array and functions implement two stacks and its opertaions (push, pop, peek)
#include<stdio.h>
#include<stdlib.h>
# define SIZE 10
int array[SIZE];
int top1=-1, top2=SIZE;
void push1(int data)
{
    if(top1<top2-1)
    {
        top1++;
        array[top1]=data;
    }
    else
    {
        printf("\nStack 1 is FULL");
    }
}
void push2(int data)
{
    if(top1<top2-1)
    {
        top2--;
        array[top2]=data;
    }
    else
    {
        printf("\nStack 2 is FULL");
    }
}
int pop1()
{
    if(top1>=0)
    {
        int i=array[top1];
        top1--;
        return i;
    }
    else
    {
        printf("\nStack 1 is EMPTY");
    }
}
int pop2()
{
    if(top2<SIZE)
    {
        int i=array[top2];
        top2--;
        return i;
    }
    else
    {
        printf("\nStack 2 is EMPTY");
    }
}
int peek1()
{
    if(top1>=0)
    {
        int i=array[top1];
        return i;
    }
    else
    {
        printf("\nStack 1 is EMPTY");
        return -1;
    }
}
int peek2()
{
    if(top2<SIZE)
    {
        int i=array[top2];
        return i;
    }
    else
    {
        printf("\nStack 2 is EMPTY");
        return -1;
    }
}
void display_1()
{
    int i;
    for(i=top1;i>=0;i--)
    {
        printf("%d ",array[i]);
    }
}
void display_2()
{
    int i;
    for(i=top2;i<SIZE;i++)
    {
        printf("%d ",array[i]);
    }
}
void main()
{
    int choice, item, ch;
    while(1)
    {
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. PEEK");
        printf("\n4. DISPLAY");
        printf("\n5. EXIT\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the element: ");
                scanf("%d",&item);
                if(top1<=top2-1)
                {
                    push1(item);
                }
                else
                {
                    push2(item);
                }
                break;
            case 2:
                if(top1>=0)
                {
                    item=pop1();
                    printf("\nPoppped Element: %d",item);
                }
                else
                {
                    item=pop2();
                    printf("\nPoppped Element: %d",item);
                }
                break;
            case 3:
                printf("Want to seek Stack 1 or Stack 2 (Enter 1 or 2) ?");
                scanf("%d",&ch);
                if(ch==1)
                {
                    item=peek1();
                    printf("\nDesired Item: %d",item);
                }
                else if(ch==2)
                {
                    item=peek2();
                    printf("\nDesired Item: %d",item);
                }
                else
                {
                    printf("\nSorry no such stack !!!");
                }
                break;
            case 4:
                printf("\nWant to display stack 1 or 2 ? (Enter 1 or 2): ");
                scanf("%d",&ch);
                if(ch==1)
                {
                    display_1();
                }
                else if(ch==2)
                {
                    display_2();
                }
                else
                {
                    printf("\nSorry no such stack !!!");
                }
                break;
            case 5:
                exit(0);
            default:
                printf("\nWrong Choice");
        }
    }
}