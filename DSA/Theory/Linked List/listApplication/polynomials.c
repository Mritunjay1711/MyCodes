#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int coeff, degree;
    struct node *next;
}node;


void createNode(int c, int d, node **s)
{
    node *r = *s;
    if(*s == NULL)
    {
        r = (node*)malloc(sizeof(node));
        r->coeff = c;
        r->degree = d;
        r->next = NULL;
        *s = r;
        r->next = (node*)malloc(sizeof(node));
        r = r->next;
        r->next = NULL;
    }
    else
    {
        while(r->next)
        {
            r = r->next;
        }
        r->coeff = c;
        r->degree = d;
        r->next = (node*)malloc(sizeof(node));
        r = r->next;
        r->next = NULL;
    }
}

void display(node *s)
{
    while(s->next)
    {
        printf("%dx^%d", s->coeff, s->degree);
        s = s->next;
        if(s->coeff >= 0)
        {
            if(s->next)
                printf("+");
        }
    }
    printf("\n");
}

void addPolynomial(node *pol1, node *pol2, node *addPoly)
{
    while(pol1->next && pol2->next)
    {
        if(pol1->degree > pol2->degree)
        {
            addPoly->degree = pol1->degree;
            addPoly->coeff = pol1->coeff;
            pol1 = pol1->next;
        }
        else if(pol2->degree > pol2->degree)
        {
            addPoly->degree = pol2->degree;
            addPoly->coeff = pol2->degree;
            pol2 = pol2->next;
        }
        else
        {
            addPoly->degree = pol1->degree;
            addPoly->coeff = pol1->coeff + pol2->coeff;
            pol1 = pol1->next;
            pol2 = pol2->next;
        }
        addPoly->next = (node*)malloc(sizeof(node));
        addPoly = addPoly->next;
        addPoly->next = NULL;
    }

    while(pol1->next || pol2->next)
    {
        if(pol1->next)
        {
            addPoly->coeff = pol1->coeff;
            addPoly->degree = pol1->degree;
            pol1 = pol1->next;
        }
        if(pol2->next)
        {
            addPoly->coeff = pol2->coeff;
            addPoly->degree = pol2->degree;
            pol2 = pol2->next;
        }
        addPoly->next = (node*)malloc(sizeof(node));
        addPoly = addPoly->next;
        addPoly->next = NULL;
    }
}

int main()
{
    node *pol1 = NULL, *pol2 = NULL, *pol3; 
    int a, c, d;
    printf("Enter the data for first polynomial\n");
    do
    {
        printf("Enter the coeff: ");
        scanf("%d", &c);
        printf("Enter the degree: ");
        scanf("%d", &d);
        createNode(c, d, &pol1);
        printf("Enter 1 to add node 0 to exit: ");
        scanf("%d", &a);
    } while (a);

    printf("Enter the data for second polynomial\n");
    do
    {
        printf("Enter the coeff: ");
        scanf("%d", &c);
        printf("Enter the degree: ");
        scanf("%d", &d);
        createNode(c, d, &pol2);
        printf("Enter 1 to add node 0 to exit: ");
        scanf("%d", &a);
    } while (a);
    
    display(pol1);
    display(pol2);
    pol3 = (node*)malloc(sizeof(node));
    addPolynomial(pol1, pol2, pol3);
    display(pol3);
    return 0;
}