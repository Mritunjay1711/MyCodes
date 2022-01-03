#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct BSTnode
{
    int roll;
    char name[20];
    float cgpa;
    struct BSTnode *left;
    struct BSTnode *right;
}BSTnode;

BSTnode *createNode(int r, char *n, float f)
{
    BSTnode *temp = (BSTnode*)malloc(sizeof(BSTnode));
    temp->roll = r;
    strcpy(temp->name, n);
    temp->cgpa = f;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

BSTnode *insert(BSTnode *root, int r, char *n, float f)
{
    if(root == NULL)
    {
        root = createNode(r, n, f);
        return root;
    }
    if(r < root->roll)
    {
        root->left = insert(root->left, r, n, f);
    }
    else
    {
        root->right = insert(root->right, r, n, f);
    }
    return root;
}

BSTnode *search(BSTnode *root, int roll)
{
    if(!root)
    {
        printf("Element not found!\n");
        return NULL;
    }
    if(root->roll == roll)
        return root;
    if(roll > root->roll)
        search(root->right, roll);
    else
        search(root->left, roll);
}



BSTnode *inSuccessor(BSTnode *root)
{
    while(root->left)
    {
        root = root->left;
    }
    return root;
}

BSTnode *delete (BSTnode *root)
{
    if (root == NULL)
    {
        return root;
    }
    else if(root->cgpa >= 5)
    {
        delete(root->left);
        delete(root->right);
    }
    else
    {
        //case 1
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
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
            root->roll = temp->roll;
            strcpy(root->name, temp->name);
            root->cgpa = temp->cgpa;
            root->right = delete (root->right);
        }
    }
    return root;
}

void preOrder(BSTnode *root)
{
    if(!root)
        return;
    printf("%d ", root->roll);
    printf("%s %f\n", root->name, root->cgpa);
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    int roll;
    char name[20];
    float cgpa;
    BSTnode *root = NULL;

    int a;
    do
    {
        printf("Enter\n1 to insert\n2 to traverse\n3 to delete cgpa below 5\n0 to exit\n");
        scanf("%d", &a);
        switch(a)
        {
            case 1:
                printf("Enter the roll: ");
                scanf("%d", &roll);
                printf("Enter the name: ");
                scanf("%s", name);
                printf("Enter the cgpa: ");
                scanf("%f", &cgpa);
                root = insert(root, roll, name, cgpa);
                break;
            case 2:
                preOrder(root);
                break;
            case 3:
                root = delete(root);
            default:
                break;
        }
        /* code */
    } while (a);
    
    return 0;
}