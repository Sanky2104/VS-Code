//Author: Sanskriti Gupta
//Date: 1 March 2022
//Aim: Check whether the string is palindrome or not using stack and queue
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CAPACITY 100
char stack[CAPACITY];
char queue[CAPACITY];
void enqueue(char data);
char dequeue();
int front=-1,rear=-1,top=-1;
void push(char i);
char pop();
void main()
{
    char i;
    int flag=0;
    char str[CAPACITY];
    char *ptr;
    ptr=str;
    printf("\nEnter the string: ");
    gets(ptr);
    for(i=0;i<strlen(str);i++)
    {
        push(str[i]);
        enqueue(str[i]);
    }
    for(i=0;i<strlen(str);i++)
    {
        if(pop()==dequeue())
        {
            continue;
        }
        else
        {
            flag++;
        }
    }
    if(flag==0)
    {
        printf("\n%s is a palindrome",str);
    }
    else
    {
        printf("\n%s is NOT a palinddome",str);
    }
}
void enqueue(char data)
{
    if((rear==CAPACITY && front==1 )|| (front==rear+1))
    {
        printf("Overflow");
    }
    else if(rear==CAPACITY)
    {
        rear=1;
    }
    else if(front==-1)
    {
        front=1;
        rear=1;
    }
    else
    {
        rear++;
    }
    queue[rear]=data;
}
char dequeue()
{
    char data;
    data=queue[front];
    if(front==-1)
    {
        printf("Underflow");
    }
    else if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else if(front==CAPACITY)
    {
        front=1;
    }
    else
    {
        front++;
    }
    return data;
}
void push(char i)
{
     if(top==CAPACITY-1)
     {  
        printf("\nStack overflow");  
     }  
     else
     {  
         top++;
         stack[top]=i;  
     }  
}
char pop()
{  
    char a;
    a= stack[top];
    top--;
    return a;
}