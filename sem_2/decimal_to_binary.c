//Author: Sanskriti Gupta
//Date: 9 March 2022
//Aim: To convert a decimal number into binary
#include<stdio.h>
#include<string.h>
int stack[100],queue[100],top=-1,front=-1,rear=-1,real_part;
float num,fraction_part;
void push(int x);
int pop();
void enqueue(int x);
int dequeue();
void real_to_binary();
void fraction_to_binary();
void convert_binary();
void main()
{
    printf("\nEnter a number: ");
    scanf("%f",&num);
    real_part=(int)num;
    fraction_part=num-real_part;
    convert_binary();
}
void push(int x)
{
    stack[++top]=x;
}
int pop()
{
    int a=stack[top];
    top--;
    printf("%d",a);
}
void enqueue(int x)
{
    queue[++rear]=x;
}
int dequeue()
{
    int a=queue[front];
    front--;
    printf("%d",a);
}
void real_to_binary()
{
    while(real_part)
    {
        push(real_part%2);
        real_part=real_part/2;
    }
}
void fraction_to_binary()
{
    int len=0;
    float a;
    for(int i=0;i!='\0';i++)
    {
        len++;
    }
    while(len)
    {
        a=2*fraction_part;
        enqueue((int)a);
        fraction_part=a-(int)a;
        len--;
    }
}
void convert_binary()
{
    real_to_binary();
    fraction_to_binary();
    while(top!=-1)
    {
        pop();
    }
    if(fraction_part!=0)
    {
        printf(".");
        while(front!=-1)
        {
            dequeue();
        }
    }
}