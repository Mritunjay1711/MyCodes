/*
Mritunjay Kumar 2006226

Schedule the following processes using SJF Preemptive Version.
PID       Arrival Time      Burst Time
P1              0                       4
P2              2                       1
P3              N                       6
P4              3                       2
P5              4                       N + 1
Consider N to be the last digit of your roll number.
Find the average Turn around time, average waiting time
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
    else if(temp->dat.bt < s->dat.bt)
    {
        temp->next = *f;
        *f = temp;
    }
    else
    {
        while(s && temp->dat.bt >= s->dat.bt)
        {
            w = s;
            s = s->next;
        }
        temp->next = w->next;
        w->next = temp;
        
        if((*r)->next == temp)
            *r = temp;
    }
}

void reEnqueue(queue **f, queue **r, data d)
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
    else if(temp->dat.bt < s->dat.bt)
    {
        temp->next = *f;
        *f = temp;
    }
    else
    {
        while(s && temp->dat.bt > s->dat.bt)
        {
            w = s;
            s = s->next;
        }
        temp->next = w->next;
        w->next = temp;
        
        if((*r)->next == temp)
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

void sort(int *arr, int n){
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the last digit of roll number: ");
    scanf("%d", &n);
    data arr[5] = {{0, 0, 4, 1}, {1, 2, 1, 0}, {2, n, 6, 0}, {3, 3, 2, 0}, {4, 4, n + 1, 0}};
    int at[] = {0, 2, n, 3, 4};
    int bt[] = {4, 1, 6, 2, n+1};
    sort(at, 5);
    data min;
    min.at = 100;
    for(int i = 0; i < 5; i++)
    {
        if(arr[i].at < min.at)
        {
            min = arr[i];
        }
    }
    queue *f = NULL, *r = NULL;
    enqueue(&f, &r, min);
    int temp = min.at;
    int leftEntry[5] = {-1, -1, -1, -1, -1};
    int ct[5];
    int tat[5];
    int wt[5];
    int rt[5], k = 1;
    while(!isEmpty(f))
    {
        min = dequeue(&f, &r);
        //If the process is interrupted in between by other process then it is checked to continue or give chance to other process here
        if(min.bt > at[k] && k < 5 && temp <= at[4])
        {
            // printf("%d**\n", k);
            if(leftEntry[min.ind] == -1)
            {
                leftEntry[min.ind] = temp;
            }
            min.bt -= (at[k] - at[k - 1]);
            temp += (at[k] - at[k - 1]);
            // printf("%d*\n", temp);
            k++;
            reEnqueue(&f, &r, min);
        }
        else
        {
            if(leftEntry[min.ind] == -1)
            {
                leftEntry[min.ind] = temp;
            }
            temp += min.bt;
            ct[min.ind] = temp;
            // printf("%d*\n", temp);
        }
        //Process are enqueued in the queue according to their arrival time
        for(int i = 0; i < 5; i++)
        {
            if(arr[i].at <= temp && arr[i].visited == 0)
            {
                arr[i].visited = 1;
                enqueue(&f, &r, arr[i]);
            }
        } 
        // display(f);
        // if(isEmpty(f))
        //     printf("Empty!\n");
    }
  
    for(int i = 0; i < 5; i++)
    {
        tat[i] = ct[i] - arr[i].at;
        wt[i] = tat[i] - bt[i];
        rt[i] = leftEntry[i] - arr[i].at;
    }


    printf("Pid  AT  BT  CT  TAT  WT  RT\n");
    for(int i = 0; i < 5; i++)
    {
        printf("P%d  %2d  %2d   %2d  %2d  %2d  %2d\n", i+1, arr[i].at, arr[i].bt, ct[i], tat[i], wt[i], rt[i]);
    }
    float avgTat = 0;
    float avgWT = 0;
    int sumT = 0, sumW = 0;
    for(int i = 0; i < 5; i++)
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