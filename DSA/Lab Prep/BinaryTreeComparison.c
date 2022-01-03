#include<stdio.h>
#include<stdlib.h>

typedef struct BSTnode
{
    int data;
    struct BSTnode *left;
    struct BSTnode *right;
}BSTnode;

BSTnode *createNode(int data)
{
    BSTnode *temp = (BSTnode*)malloc(sizeof(BSTnode));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

BSTnode *insert(BSTnode *root, int data)
{
    if(root == NULL)
    {
        root = createNode(data);
        return root;
    }
    if(data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

void inOrder(BSTnode *root)
{
    if(!root)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

int Compare(BSTnode *root1, BSTnode *root2)
{
    if((!root1 && root2) || (root1 && !root2))
        return 0;
    if(!root1 && !root2)
        return 1;
        
    if(root1->data == root2->data && Compare(root1->left, root2->left) && Compare(root1->right, root2->right))
        return 1;
    else
        return 0;
}

int main()
{
    int a, data;
    BSTnode *root1 = NULL, *root2 = NULL;
    do
    {
        printf("Enter data: ");
        scanf("%d", &data);
        root1 = insert(root1, data);
        printf("Enter 1 to add data: ");
        scanf("%d", &a);
    } while (a);
    do
    {
        printf("Enter data: ");
        scanf("%d", &data);
        root2 = insert(root2, data);
        printf("Enter 1 to add data: ");
        scanf("%d", &a);
        /* code */
    } while (a);
    
    printf("%d\n", Compare(root1, root2));
    return 0;
}