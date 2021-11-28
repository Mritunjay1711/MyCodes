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
    else if(data > root->data)
    {
        root->right = insert(root->right, data);
    }
    else
        printf("Data already exist!\n");
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

int noOfNodes(BSTnode *root)
{
    if(!root)
        return 0;
    return 1 + noOfNodes(root->left) + noOfNodes(root->right);
}

int sumOfNodes(BSTnode *root)
{
    if(root == NULL)
        return 0;
    static int sum = 0;
    return (root->data + sumOfNodes(root->right) + sumOfNodes(root->left));
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int depth(BSTnode *root)
{
    if(!root)
        return 0;
    return 1 + max(depth(root->left), depth(root->right));
}

int isBST(BSTnode *root)
{
    static BSTnode *prev = NULL;
    if(root != NULL)
    {
        if(!isBST(root->left))
        {
            return 0;
        }
        if(prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);

    }
    else
        return 1;
}

int noOfLeaf(BSTnode *root)
{
    if(!root)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    else
        return noOfLeaf(root->left) + noOfLeaf(root->right);
}

void NodesAtMaxDepth(BSTnode *root, int k)
{
    if(root == NULL || k < 0)
        return;
    if(k == 0)
    {
        printf("%d ", root->data);
        return;
    }
    NodesAtMaxDepth(root->left, k-1);
    NodesAtMaxDepth(root->right, k-1);
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
        printf("Enter\n1 to add node\n2 for preOrder traversal\n3 for inOrder traversal\n4 for postOrder traversal\n5 for search\n6 for smallest element\n7 for largest element\n8 for delete\n9 for number of nodes\n10 for sum of nodes\n11 for depth\n12 for number of leaf node\n13 for number of non-leaf node\n14 for Checking BST\n0 to exit\n");
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
        case 9:
            printf("Number of nodes: %d\n", noOfNodes(root));
            break;
        case 10:
            printf("Sum of nodes: %d\n", sumOfNodes(root));
            break;
        case 11:
            printf("Depth of the tree: %d\n", depth(root));
            break;
        case 12:
            printf("Number of leaf node: %d\n", noOfLeaf(root));
            break;
        case 13:
            printf("Number of non-leaf node: %d\n", noOfNodes(root) - noOfLeaf(root));
            break;
        case 14:
            if(isBST(root))
                printf("This is BST!\n");
            else
                printf("Not a BST!\n");
            break;
        default:
            break;
        }
    } while (a);

    return 0;
}