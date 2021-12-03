#include <stdio.h>
#include <stdlib.h>
struct treenode
{
    struct treenode *left;
    int data;
    struct treenode *right;
};
struct treenode *create(int data)
{
    struct treenode *new = (struct treenode *)malloc(sizeof(struct treenode));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}
void inorder(struct treenode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}
struct treenode *insert(struct treenode *node, int data)
{
    if (node == NULL)
    {
        return create(data);
    }
    if (data < node->data)
    {
        node->left = insert(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = insert(node->right, data);
    }

    return node;
}

int depth(struct treenode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        if (depth(root->left) > depth(root->right))
        {
            return depth(root->left) + 1;
        }
        else
        {
            return depth(root->right) + 1;
        }
    }
}

int printlevelorder(struct treenode *root, int level)
{
    if (root == NULL)
    {
        return 0;
    }
    if (level == 1)
    {
        printf("%d ", root->data);
        return 1;
    }
    int left = printlevelorder(root->left, level - 1);
    int right = printlevelorder(root->right, level - 1);

    return left || right;
}
void levelordertraversal(struct treenode *root)
{
    int level = 1;
    while (printlevelorder(root, level))
    {
        level++;
        printf("\n");
    }
}

int main()
{
    struct treenode *root = NULL;
    root = insert(root, 50);
    insert(root, 15);
    insert(root, 62);
    insert(root, 5);
    insert(root, 20);
    insert(root, 58);
    insert(root, 3);
    insert(root, 8);
    insert(root, 37);
    insert(root, 60);
    insert(root, 24);
    depth(root);
    levelordertraversal(root);
}