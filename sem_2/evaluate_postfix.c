//Author: Sanskriti Gupta
//Aim: Evaluate postfix expression using stack and array
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define SIZE 100
int stack[SIZE], top=-1;
void push(int item);
int pop();
void evaluate_postfix(char postfix[]);
void main()
{
    int i;
    char postfix[SIZE];
    printf("\nEnter the postfix expression (enter ) to end): ");
    for(i=0;i<SIZE-1;i++)
    {
        scanf("%c",&postfix[i]);
        if(postfix[i]==')')
        {
            break;
        }
    }
    evaluate_postfix(postfix);
}
void push(int item)
{
    if(top>=SIZE-1)
    {
        printf("\nStack Overflow");
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
        int item=stack[top];
        top--;
        return item;
    }
}
void evaluate_postfix(char postfix[])
{
    int i,val,A,B;
    char ch;
    for(i=0;postfix[i]!=')';i++)
    {
        ch=postfix[i];
        if(isdigit(ch))
        {
            push(ch-'0');
        }
        else if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
        {
            A=pop();
            B=pop();
            switch(ch)
            {
                case '*':
                    val=B*A;
                    break;
                case '/':
                    val=B/A;
                    break;
                case '+':
                    val=B+A;
                    break;
                case '-':
                    val=B-A;
                    break;
                case '^':
                    val=pow(A,B);
                    break;
            }
            push(val);
        }
    }
    printf("\nResult of expression evaluation: %d\n",pop());
}