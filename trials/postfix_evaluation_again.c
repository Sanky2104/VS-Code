//Author: Sanskriti Gupta
//Date: 17 April 2022
//Aim: To evaluate postsix expression
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define size 100
int stack[size],top=-1;
void push(int item)
{
    if(top>=size-1)
    {
        printf("\nOverflow");
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
        printf("\nUnderflow");
    }
    else
    {
        int i=stack[top];
        top--;
        return i;
    }
}
void evaluate_postfix(char postfix[])
{
    int i;
    char ch;
    for(i=0;postfix[i]!=')';i++)
    {
        ch=postfix[i];
        if(isdigit(ch))
        {
            push(ch-'0');
        }
        else if(ch=='+' ||ch=='-'||ch=='/' ||ch=='*')
        {
            int A=pop();
            int B=pop();
            switch(ch)
            {
                case '+':
                    push(B+A);
                    break;
                case '-':
                    push(B-A);
                    break;
                case '/':
                    push(B/A);
                    break;
                case '*':
                    push(B*A);
                    break;
            }
        }
    }
    printf("\nResult of Expression: %d",pop());
}
void main()
{
    int i;
    char postfix[size];
    printf("\nEnter the postfix expression, enter ')' to end: ");
    for(i=0;i<size-1;i++)
    {
        scanf("%c",&postfix[i]);
        if(postfix[i]==')')
        {
            break;
        }
    }
    evaluate_postfix(postfix);
}