#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *left;
    int data;
    struct node *right;
}node;

node *createNode(int data)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->left = NULL;
    temp->data = data;
    temp->right = NULL;
    return temp;
}

void preOrder(node *root)
{
    if(root)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(node *root)
{
    if(root)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void postOrder(node *root)
{
    if(root)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int heightTree(node *root)
{
    if(!root)
        return 0;
    else
    {
        return 1 + max(heightTree(root->left), heightTree(root->right));
    }
}

int nodes(node *root)
{
    if(!root)
        return 0;
    else
        return 1 + nodes(root->left) + nodes(root->right);
}

int main()
{
    node *r = createNode(10);
    node *l1 = createNode(9);
    node *l2 = createNode(1);
    node *r1 = createNode(2);
    node *r2 = createNode(8);
    node *l3 = createNode(6);
    node *r3 = createNode(7);

    //linking
    r->left = l1;
    r->right = r1;
    l1->left = l2;
    l1->right = r2;
    r1->left = l3;
    r1->right = r3;

    /*
            10
           /  \
          9     2
         /\    / \ 
        1  8  6   7
    */
   postOrder(r);
   printf("\n%d", heightTree(r) - 1);
   printf("\n%d", nodes(r));
    return 0;
}