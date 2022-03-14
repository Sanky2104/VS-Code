//Author: Sanskriti Gupta
//Date: 13 March 2022
//Aim: To implement pre-order in a static tree
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    char data;
    struct Node *right;
    struct Node *left;
};
struct Node *root;
struct Node *stack[100],*data;
int top=1;
void push(struct Node *data);
char pop();
void pre_order();
struct Node *new_node(char data);
int main()
{
    char data='A';
    struct Node *root=new_node(data);
    data='B';
    root->left=new_node(data);
    data='C';
    root->right=new_node(data);
    data='F';
    root->right->right=new_node(data);
    data='D';
    root->left->left=new_node(data);
    data='F';
    root->left->right=new_node(data);
    pre_order();
    return 0;
}
void pre_order()
{
    push(NULL);
    struct Node *ptr=root;
    while(ptr!=NULL)
    {
        printf("%c",ptr->data);
        if(ptr->right!=NULL)
        {
            push(ptr->right);
        }
        if(ptr->left!=NULL)
        {
            ptr=ptr->left;
        }
        else
        {
            pop();
            ptr=stack[top];
        }
    }
}
void push(struct Node *data)
{
    top++;
    stack[top]=data;
}
char pop()
{
    struct Node *a=stack[top];
    top--;
    printf("%c",a->data);
}
struct Node *new_node(char data)
{
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=data;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}