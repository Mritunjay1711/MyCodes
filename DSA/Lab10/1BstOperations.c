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

BSTnode *search(BSTnode *root, int key)
{
    if(!root)
    {
        printf("Element not found!\n");
        return NULL;
    }
    if(root->data == key)
        return root;
    if(key > root->data)
        search(root->right, key);
    else
        search(root->left, key);
}

int smallest(BSTnode *root)
{
    if(!root)
        return -1;
    while(root->left)
    {
        root = root->left;
    }
    return root->data;
}

int largest(BSTnode *root)
{
    if(!root)
        return -1;
    while (root->right)
        root = root->right;
    return root->data;
}

BSTnode *inSuccessor(BSTnode *root)
{
    while(root->left)
    {
        root = root->left;
    }
    return root;
}

BSTnode *delete (BSTnode *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if (data < root->data)
    {
        root->left = delete (root->left, data);
    }
    else if (data > root->data)
    {
        root->right = delete (root->right, data);
    }
    else
    {
        //case 1
        if (root->left == NULL && root->right == NULL)
        {
            printf("Invoking!\n");
            free(root);
            root = NULL;
            printf("%u\n", root);
        }
        //case 2
        else if (root->left == NULL)
        {
            BSTnode *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            BSTnode *temp = root;
            root = root->left;
            free(temp);
        }
        //case 3
        else
        {
            BSTnode *temp = inSuccessor(root->right);
            root->data = temp->data;
            root->right = delete (root->right, temp->data);
        }
    }
    return root;
}

void preOrder(BSTnode *root)
{
    if(!root)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(BSTnode *root)
{
    if(!root)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

void inOrder(BSTnode *root)
{
    if(!root)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

int main()
{
    BSTnode *root = NULL;
    int a, data;
    do
    {
        printf("Enter\n1 to add node\n2 for preOrder traversal\n3 for inOrder traversal\n4 for postOrder traversal\n5 for search\n6 for smallest element\n7 for largest element\n8 for delete\n0 to exit\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            preOrder(root);
            printf("\n");
            break;
        case 3:
            inOrder(root);
            printf("\n");
            break;
        case 4:
            postOrder(root);
            printf("\n");
            break;
        case 5:
            printf("Enter the data to search: ");
            scanf("%d", &data);
            BSTnode *ptr;
            ptr = search(root, data);
            if(ptr != NULL)
                printf("Element found at %u\n", ptr);
            break;
        case 6:
            printf("Smallest element: %d\n", smallest(root));
            break;
        case 7:
            printf("Largest element: %d\n", largest(root));
            break;
        case 8:
            printf("Enter the data to delete: ");
            scanf("%d", &data);
            root = delete(root, data);
            break;
        default:
            break;
        }
    } while (a);

    return 0;
}