#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct node
{
    int coeff;
    int xpow, ypow, zpow;
    struct node *next;
}node;

long long int CalcValue(node *top, int x, int y, int z)
{
    long long int val = 0;
    while(top)
    {
        val += (top->coeff * pow(x, top->xpow) * pow(y, top->ypow) * pow(z, top->zpow));
        // printf("%ld\n", val);
        top = top->next;
    }
    return val;
}

node *createNode(int coeff, int xp, int yp, int zp)
{
    node *ptr = (node*)malloc(sizeof(node));
    ptr->coeff = coeff;
    ptr->xpow = xp;
    ptr->ypow = yp;
    ptr->zpow = zp;
    ptr->next = NULL;
    return ptr;
}

void insert(node **top, int coeff, int xp, int yp, int zp)
{
    node *temp = *top;
    if(temp == NULL)
    {
        *top = createNode(coeff, xp, yp, zp);
    }
    else
    {
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = createNode(coeff, xp, yp, zp);
    }
}

void display(node *top)
{
    while(top->next)
    {
        printf("(%dx^%dy^%dz^%d) + ", top->coeff, top->xpow, top->ypow, top->zpow);
        top = top->next;
    }
    printf("(%dx^%dy^%dz^%d)", top->coeff, top->xpow, top->ypow, top->zpow);
}

int main()
{
    int a, data, xp, yp, zp, n;
    printf("Enter the number of data: ");
    scanf("%d", &n);
    node *top = NULL;
    for(int i = 0; i < n; i++)
    {
        printf("Enter the coeff: ");
        scanf("%d", &data);
        printf("Enter the pow of x: ");
        scanf("%d", &xp);
        printf("Enter the pow of y: ");
        scanf("%d", &yp);
        printf("Enter the pow of z: ");
        scanf("%d", &zp);
        insert(&top, data, xp, yp, zp);
    }
    int x, y, z;
    printf("Enter the value of x, y and z: ");
    scanf("%d%d%d", &x, &y, &z);
    printf("%ld is the ans\n", CalcValue(top, x, y, z));
    display(top);
    return 0;
}