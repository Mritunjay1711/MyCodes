/*
Q2) Implement Round Robin Scheduling. TQ = N where N is last digit of your roll. Find Av TAT and Av WT and Number of times context switching took place. Comment what is the optimal value of TQ. Should it be large or small, justify your claim.
PID    AT   BT
P1      0      5
P2      1      4
P3      2      2
P4      4      1

Mritunjay Kumar 2006226
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct data{
    int ind, at, bt, visited;
}data;

typedef struct queue{
    data dat;
    struct queue *next;
}queue;

int isFull(queue *q)
{
    queue *r = (queue*)malloc(sizeof(queue));
    return r == NULL;
}

int isEmpty(queue *q)
{
    return q == NULL;
}

void enqueue(queue **f, queue **r, data d)
{
    queue *temp = (queue*)malloc(sizeof(queue));
    temp->dat = d;
    temp->next = NULL;
    queue *s = *f, *w = *f;
    if(isFull(*f))
        printf("Overflow!\n");
    else if(*f == NULL && *r == NULL)
    {
        *f = *r = temp;
    }
    else
    {
        (*r)->next = temp;
        *r = temp;
    }
}

data dequeue(queue **f, queue **r)
{
    data val;
    if(isEmpty(*f))
    {
        printf("Underflow!\n");
    }
    else if(*f == *r)
    {
        val = (*f)->dat;
        *f = *r = NULL;
    }
    else
    {
        val = (*f)->dat;
        (*f) = (*f)->next;
    }
    return val;
}


void display(queue *f)
{
    while(f)
    {
        printf("%d ", f->dat.bt);
        f = f->next;
    }
    printf("\n");
}

int main()
{
    data arr[4] = {{0, 0, 5, 1}, {1, 1, 4, 0}, {2, 2, 2, 0}, {3, 4, 1, 0}};
    int leftEntry[4] = {-1, -1, -1, -1};
    int ct[4];
    int bt[4] = {5, 4, 2, 1};
    int tat[4];
    int wt[4];
    int rt[4];
    queue *f = NULL, *r = NULL;
    int n, temp, ind;
    printf("Enter the last digit of roll number: ");
    scanf("%d", &n);
    data min;
    min.at = 100;
    for(int i = 0; i < 4; i++)
    {
        if(arr[i].at < min.at)
        {
            min = arr[i];
        }
    }
    enqueue(&f, &r, min);
    temp = min.at;
    ind = min.ind;
    while(!isEmpty(f))
    {
        min = dequeue(&f, &r);
        if(min.bt > n)
        {
            if(leftEntry[min.ind] == -1)
            {
                leftEntry[min.ind] = temp;
            }
            min.bt -= n;
            temp += n;
            for(int i = 0; i < 4; i++)
            {
                if(arr[i].at <= temp && arr[i].visited == 0)
                {
                    arr[i].visited = 1;
                    enqueue(&f, &r, arr[i]);
                }
            }
            enqueue(&f, &r, min); 
        }
        else
        {
            if(leftEntry[min.ind] == -1)
            {
                leftEntry[min.ind] = temp;
            }
            temp += min.bt;
            ct[min.ind] = temp;
            for(int i = 0; i < 4; i++)
            {
                if(arr[i].at <= temp && arr[i].visited == 0)
                {
                    arr[i].visited = 1;
                    enqueue(&f, &r, arr[i]);
                }
            }
        }
    }
    for(int i = 0; i < 4; i++)
    {
        tat[i] = ct[i] - arr[i].at;
        wt[i] = tat[i] - arr[i].bt;
        rt[i] = leftEntry[i] - arr[i].at;
    }


    printf("Pid  AT  BT  CT  TAT  WT  RT\n");
    for(int i = 0; i < 4; i++)
    {
        printf("P%d  %2d  %2d   %2d  %2d  %2d  %2d\n", i+1, arr[i].at, arr[i].bt, ct[i], tat[i], wt[i], rt[i]);
    }
    float avgTat = 0;
    float avgWT = 0;
    int sumT = 0, sumW = 0;
    for(int i = 0; i < 4; i++)
    {
        sumT += tat[i];
        sumW += wt[i];
    }
    avgTat = sumT / 5.0;
    avgWT = sumW / 5.0;
    printf("Average TAT: %.2f\n", avgTat);
    printf("Average WT: %.2f\n", avgWT);
    return 0;
}