#include<stdio.h>
#include<stdlib.h>

typedef struct PQueue
{
    int data;
    int prio;
    struct PQueue *next;
}PQueue;

void enqueue(PQueue **f, PQueue **r, int d, int p)
{
    PQueue *s = *r;
    if(s == NULL)
    {
        s = (PQueue*)malloc(sizeof(PQueue));
        s->data = d;
        s->prio = p;
        s->next = NULL;
        *f = s;
        *r = s;
    }
    else
    {
        s->next = (PQueue*)malloc(sizeof(PQueue));
        s = s->next;
        s->data = d;
        s->prio = p;
        s->next = NULL;
        *r = s;
    }
}

void dequeue(PQueue **q)
{
    PQueue *s, *r, *t;
    r = s = *q;
    while(s->next)
    {
        if(s->next->prio < r->prio)
        {
            t = s; // t is node before the lowest prio(which is need to be dequeued first)
            r = s->next; // r is that particular node with the lowest priority
        }
        s = s->next;
    }
    t->next = r->next;
    free(r);    
}

void traversal(PQueue *q)
{
    while(q != NULL)
    {
        printf("Data: %d\n", q->data);
        printf("Prio: %d\n", q->prio);
        q = q->next;
    }
}

int main()
{
    PQueue *f = (PQueue*)malloc(sizeof(PQueue));
    PQueue *r = (PQueue*)malloc(sizeof(PQueue));
    f = r = NULL;
    enqueue(&f, &r, 23, 3);
    enqueue(&f, &r, 15, 1);
    enqueue(&f, &r, 76, 2);
    enqueue(&f, &r, 56, 5);
    enqueue(&f, &r, 46, 4);
    // traversal(f);
    dequeue(&f);
    // dequeue(&f);
    traversal(f);
    return 0;
}