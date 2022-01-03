#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

typedef struct node
{
    struct node *left;
    int data;
    struct node *right;
} node;

typedef struct seqTree
{
    int ind;
    int *arr;
} seqTree;

node *createNode(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->left = NULL;
    temp->data = data;
    temp->right = NULL;
    return temp;
}

typedef struct stack
{
    int size;
    int top;
    node *arr[SIZE];
} stack;

int isEmpty(stack *s)
{
    return s->top == -1;
}

int isFull(stack *s)
{
    return s->top == s->size - 1;
}

void push(stack *s, node *data)
{
    if (!isFull(s))
    {
        s->top++;
        s->arr[s->top] = data;
        // printf("%d pushed!\n", data);
    }
    else
        printf("Stack Overflow!, Cannot push %d in Stack.\n", data);
}

node *pop(stack *s)
{
    if (!isEmpty(s))
    {
        node *val = s->arr[s->top];
        s->top--;
        return val;
    }
    else
    {
        printf("Stack Underflow.\n");
        return NULL;
    }
}

node *peek(stack s)
{
    return s.arr[s.top];
}

//Iterative method
void PreOrder(node *root){
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

//Iterative method
void InOrder(node *root)
{
    if(root == NULL)
        return;
    stack s;
    s.top = -1;
    s.size = SIZE;
    node *current = root;
    int count = 1;
    while(count)
    {
        if(current)
        {
            push(&s, current);
            current = current->left;
        }
        else
        {
            if(!isEmpty(&s))
            {
                current = pop(&s);
                printf("%d ", current->data);
                current = current->right;
            }
            else
                count = 0;
        }
    }
}

//Iterative method
void PostOrder(node *root)
{
    if(root == NULL)
        return;
    
    stack s;
    s.top = -1;
    s.size = SIZE;
    do
    {
        while(root)
        {
            if(root->right)
                push(&s, root->right);
            push(&s, root);
            root = root->left;
        }
     
        root = pop(&s);
        if (root->right && peek(s) == root->right)
        {
            pop(&s);
            push(&s, root);
            root = root->right;
        }
        else
        {
            printf("%d ", root->data);
            root = NULL;
        }
    }while(!isEmpty(&s));
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
    if (root)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void postOrder(node *root)
{
    if (root)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void setRoot(seqTree *tree, int data)
{
    if (tree->arr[0] != -1)
    {
        printf("Root already exist!\n");
    }
    else
    {
        tree->arr[0] = data;
        tree->ind = 0;
    }
}

void setLeft(seqTree *tree, int data, int parent)
{
    if (tree->arr[parent] == -1)
    {
        printf("No parent found!\n");
    }
    else
    {
        tree->arr[parent * 2 + 1] = data;
        if (tree->ind < (parent * 2 + 1))
            tree->ind = (parent * 2 + 1);
    }
}

void setRight(seqTree *tree, int data, int parent)
{
    if (tree->arr[parent] == -1)
    {
        printf("No parent found!\n");
    }
    else
    {
        tree->arr[parent * 2 + 2] = data;
        if (tree->ind < (parent * 2 + 2))
            tree->ind = (parent * 2 + 2);
    }
}

void printTree(seqTree tree)
{
    for (int i = 0; i <= tree.ind; i++)
    {
        if (tree.arr[i] == -1)
        {
            printf("- ");
        }
        else
        {
            printf("%d ", tree.arr[i]);
        }
    }
    printf("\n");
}

int main()
{
    int a;
    printf("Enter\n1 for sequential\n2 for linked\n");
    scanf("%d", &a);
    seqTree tree;
    node *r = createNode(10);
    node *l1 = createNode(9);
    node *l2 = createNode(1);
    node *r1 = createNode(2);
    node *r2 = createNode(8);
    node *l3 = createNode(6);
    node *r3 = createNode(7);
    switch (a)
    {
    case 1:
        tree.arr = (int *)malloc(SIZE * sizeof(int));
        for (int i = 0; i < SIZE; i++)
        {
            tree.arr[i] = -1;
        }
        setRoot(&tree, 10);
        setLeft(&tree, 9, 0);
        setRight(&tree, 2, 0);
        setLeft(&tree, 1, 1);
        setRight(&tree, 8, 1);
        setLeft(&tree, 6, 2);
        setRight(&tree, 7, 2);

        printTree(tree);
        break;
    case 2:

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
        int b, i;
        do{
            printf("\nEnter\n1 for preOrder\n2 for inOrder\n3 for postOrder\n0 for exit\n");
            scanf("%d", &b);
            switch (b)
            {
            case 1:
                printf("Enter\n1 for Iterative\n2 for Recursion");
                scanf("%d", &i);
                if(i == 1)
                    preOrder(r);
                if(i == 2)
                    PreOrder(r);
                break;
            case 2:
                printf("Enter\n1 for Iterative\n2 for Recursion");
                scanf("%d", &i);
                if(i == 1)
                    inOrder(r);
                if(i == 2)
                    InOrder(r);
                break;
            case 3:
                printf("Enter\n1 for Iterative\n2 for Recursion");
                scanf("%d", &i);
                if(i == 1)
                    postOrder(r);
                if(i == 2)
                    PostOrder(r);
                break;
            default:
                break;
            }
        }while(b);
        break;
    }

    return 0;
}