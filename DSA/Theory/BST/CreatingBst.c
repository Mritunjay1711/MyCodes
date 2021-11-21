#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *left;
    int data;
    struct node *right;
} node;

node *createNode(node *root, int key)
{
    root = (node *)malloc(sizeof(node));
    root->data = key;
    root->left = NULL;
    root->right = NULL;
    return root;
}

node *createBST(node *root, int key)
{
    node *temp = root, *ptr;
    if (root == NULL)
    {
        root = createNode(root, key);
        return root;
    }
    else
    {
        while (temp)
        {
            if (temp->data > key)
            {
                ptr = temp;
                temp = temp->left;
            }
            else if (temp->data < key)
            {
                ptr = temp;
                temp = temp->right;
            }
            else
            {
                printf("Key already exist!\n");
                return root;
            }
        }
        if (key < ptr->data)
        {
            ptr->left = createNode(ptr->left, key);
        }
        else
            ptr->right = createNode(ptr->right, key);

        return root;
    }
}

void preOrder(node *root)
{
    if (root)
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

int main()
{
    node *root = NULL;
    int a, data;
    do
    {
        printf("Enter\n1 to add node\n2 for preOrder traversal\n3 for inOrder traversal\n4 for postOrder traversal\n0 to exit\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            root = createBST(root, data);
            break;
        case 2:
            preOrder(root);
            break;
        case 3:
            inOrder(root);
            break;
        case 4:
            postOrder(root);
            break;
        default:
            break;
        }
    } while (a);

    return 0;
}