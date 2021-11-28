#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
}node;

int getHeight(node *root)
{
    if(root == NULL)
        return 0;
    return root->height;
}

node *createNode(int data)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;
    return temp;
}

int getBalanceFactor(node *root)
{
    if(!root)
        return 0;
    return getHeight(root->left) - getHeight(root->right);
}

int max(int a, int b)
{
    return a > b ? a : b;
}

node *leftRotate(node *x)
{
    node *y = x->right;
    node *yl = y->left;

    y->left = x;
    x->right = yl;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

node *rightRotation(node *y)
{
    node *x = y->left;
    node *xr = x->right;

    x->right = y;
    y->left = xr;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return x;
}

int main()
{
    
    return 0;
}