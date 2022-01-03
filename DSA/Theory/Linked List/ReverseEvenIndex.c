#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createNode(int data)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->next = NULL;

    return p;
}

void traversal(struct node *head)
{
    while(head)
    {
        printf("%d-->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void display(struct node *head)
{
    if(head)
    {
        printf("%d-->", head->data);
        display(head->next);
    }
}

void displayReverse(struct node *head)
{
    if(head)
    {
        displayReverse(head->next);
        printf("%d-->", head->data);
    }
}

// Reverse elements at even index
void reverseEvenInd(struct node *head)
{
    struct node *odd = head, *even = NULL, *temp;
    if(odd == NULL || odd->next == NULL || odd->next->next == NULL)
        return;
    
    // Making 2 separate list 
    while(odd && odd->next)
    {
        temp = odd->next;
        odd->next = temp->next;

        temp->next = even;
        even = temp;

        odd = odd->next;
    }
    odd = head;


    // Merging the lists
    while(even)
    {
        temp = even->next;

        even->next = odd->next;
        odd->next = even;

        even = temp; // point even to even list
        odd = odd->next->next;// move odd to next odd
    }

}

int main()
{
    int a, data;
    struct node *head = NULL, *t;
    printf("Enter the number of nodes: ");
    scanf("%d", &a);
    printf("Enter the data: ");
    scanf("%d", &data);
    t = createNode(data);
    head = t;
    do
    {
        printf("Enter the data: ");
        scanf("%d", &data);
        t = createNode(data);
        struct node *w = head;
        while (w->next != NULL)
        {
            w = w->next;
        }
        w->next = t;
        a--;
    } while (a - 1);

    traversal(head);
    // display(head);
    // printf("NULL\n");
    // displayReverse(head);
    reverseEvenInd(head);
    traversal(head);
    return 0;
}

// |    |---->|    |---->|    |---->|    |---->|    |---->|    |---->NULL