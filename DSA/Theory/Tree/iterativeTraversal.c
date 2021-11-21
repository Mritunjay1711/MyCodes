#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *left;
    int data;
    struct node *right;
}node;



void postOrder(node *root){
    if(root == NULL)
        return;
    stack s;
    s.top = -1;
    s.size = 100;
    push(&s, root);
    while(!isEmpty(&s))
    {
        node *ptr = pop(&s);
        printf("%d ", ptr->data);


        if(ptr->right)
            push(&s, ptr->right);
        if(ptr->left)
            push(&s, ptr->left);
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
   preOrder(r);
   printf("\n%d", heightTree(r) - 1);
   printf("\n%d", nodes(r));
    return 0;
}