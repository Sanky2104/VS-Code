//Author: Sanskriti Gupta
//Date: 22 March 2022
//Aim: To perform pre-order, post-order, in-order and level-order in a tree
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *right,*left;
};
void pre_traversal(struct Node *root);
void post_traversal(struct Node *root);
void in_traversal(struct Node *root);
void level_traversal(struct Node *root);
int height(struct Node *root);
void current_level(struct Node *root, int i);
struct Node *create_node(int item);
int main()
{
    struct Node *root=create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4);
    root->left->right = create_node(5);
    printf("\nPre-order Traversal: ");
    pre_traversal(root);
    printf("\nPost-order Traversal: ");
    post_traversal(root);
    printf("\nIn-order Traversal: ");
    in_traversal(root);
    printf("\nLevel-order Traversal: ");
    level_traversal(root);
    printf("\n\n");
    return 0;
}
struct Node *create_node(int item)
{
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=item;
    temp->right=NULL;
    temp->left=NULL;
}
void pre_traversal(struct Node *root)
{
    struct Node *node=root;
    if(node==NULL)
    {
        return ;
    }
    printf("%d ",node->data);
    pre_traversal(node->left);
    pre_traversal(node->right);
}
void post_traversal(struct Node *root)
{
    struct Node *node=root;
    if(node==NULL)
    {
        return ;
    }
    post_traversal(node->left);
    post_traversal(node->right);
    printf("%d ",node->data);
}
void in_traversal(struct Node *root)
{
    struct Node *node=root;
    if(node==NULL)
    {
        return ;
    }
    in_traversal(node->left);
    printf("%d ",node->data);
    in_traversal(node->right);
}
int height(struct Node *root)
{
    struct Node *node=root;
    if(node==NULL)
    {
        return 0;
    }
    else
    {
        int lheight=height(node->left);
        int rheight=height(node->right);
        if(lheight>rheight)
        {
            return lheight+1;
        }
        else
        {
            return rheight+1;
        }
    }
}
void current_level(struct Node *root, int level)
{
    if(root==NULL)
    {
        return ;
    }
    if(level==1)
    {
        printf("%d ",root->data);
    }
    else if(level>1)
    {
        current_level(root->left,level-1);
        current_level(root->right,level-1);
    }
}
void level_traversal(struct Node *root)
{
    int h=height(root);
    int i;
    for(i=1; i<=h; i++)
    {
        current_level(root,i);
    }
}