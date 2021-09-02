#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

void removeLoop(node *loopNode, node *head);

void traversal(node *head)
{
    while(head)
    {
        printf("%d-->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

node *createNode(int data)
{
    node *p = (node *)malloc(sizeof(node));
    p->data = data;
    p->next = NULL;
    return p;
}

int detectLoop(node *s)
{
    node *slow = s;
    node *fast = s;

    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            removeLoop(slow, s);
            return 1;
        }
    }
    return 0;
}

void removeLoop(node *loopNode, node *head)
{
    node *p = loopNode;
    node *s = loopNode;

    int k = 1, i;

    // Counting the number of nodes in loop
    while(p->next != s)
    {
        p = p->next;
        k++;
    }

    p = head;
    s = head; // We will move this pointer k nodes after head

    for(i = 0; i < k; i++)
        s = s->next;

    // If we move both pointer at same pase now, they will meet at starting of loop
    while(p != s)
    {
        p = p->next;
        s = s->next;
    }

    // Moving s to last node of loop
    while(s->next != p)
        s = s->next;
    
    // Pointing next of last node of loop to NULL
    s->next = NULL;
}

int main()
{
    node *head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(49);
    head->next->next->next = createNode(9);
    head->next->next->next->next = createNode(34);
    head->next->next->next->next->next = createNode(38);

    // Creating loop
    head->next->next->next->next->next->next = head->next->next;
    if(detectLoop(head))
        printf("Loop detected!\n");
    else
        printf("There is no loop!\n");

    printf("After removing loop: ");
    traversal(head);
    
    return 0;
}