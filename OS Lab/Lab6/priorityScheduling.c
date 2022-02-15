#include<stdio.h>
#include<stdlib.h>

typedef struct data{
    int ind, prior, at, bt, visited;
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
    else if(temp->dat.prior < s->dat.prior)
    {
        temp->next = *f;
        *f = temp;
    }
    else
    {
        while(s && temp->dat.prior >= s->dat.prior)
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

void Henqueue(queue **f, queue **r, data d)
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
    else if(temp->dat.prior > s->dat.prior)
    {
        temp->next = *f;
        *f = temp;
    }
    else
    {
        while(s && temp->dat.prior <= s->dat.prior)
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
    else if(temp->dat.prior < s->dat.prior)
    {
        temp->next = *f;
        *f = temp;
    }
    else
    {
        while(s && temp->dat.prior > s->dat.prior)
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

void HreEnqueue(queue **f, queue **r, data d)
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
    else if(temp->dat.prior > s->dat.prior)
    {
        temp->next = *f;
        *f = temp;
    }
    else
    {
        while(s && temp->dat.prior < s->dat.prior)
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
        printf("%d ", f->dat.prior);
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
    data arr[5] = {{0, 2, 0 , 4, 1}, {1, 3, 1, 3, 0}, {2, 4, 2, 1, 0}, {3, n, 3, 5, 0}, {4, 5, 4, n - 1, 0}};
    int at[] = {0, 1, 2, 3, 4, 5};
    int bt[] = {4, 3, 1, 5, n-1};
    sort(at, 5);
    data min, prev;
    min.at = 100;
    for(int i = 0; i < 5; i++)
    {
        if(arr[i].at < min.at)
        {
            min = arr[i];
        }
    }
    queue *f = NULL, *r = NULL;
    
    int temp = min.at;
    int leftEntry[5] = {-1, -1, -1, -1, -1};
    int ct[5];
    int tat[5];
    int wt[5];
    int rt[5], k = 1, count = 0, a;
    printf("Enter\n1 for Low No. High Prio\n2 for High No. High Prio:\n");
    scanf("%d", &a);
    if(a == 1){
        enqueue(&f, &r, min);
        while(!isEmpty(f))
        {
            prev = min;
            min = dequeue(&f, &r);
            if(prev.ind != min.ind)
            {
                count++;
            }
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
    }
    else if (a == 2){
        Henqueue(&f, &r, min);
        while(!isEmpty(f))
        {
            prev = min;
            min = dequeue(&f, &r);
            if(prev.ind != min.ind)
            {
                count++;
            }
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
                HreEnqueue(&f, &r, min);
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
                    Henqueue(&f, &r, arr[i]);
                }
            } 
            // display(f);
            // if(isEmpty(f))
            //     printf("Empty!\n");
        }
    }
    else
        printf("Invalid input!\n");

    
  
    for(int i = 0; i < 5; i++)
    {
        tat[i] = ct[i] - arr[i].at;
        wt[i] = tat[i] - bt[i];
        rt[i] = leftEntry[i] - arr[i].at;
    }


    printf("Pid Prio AT  BT  CT  TAT  WT  RT\n");
    for(int i = 0; i < 5; i++)
    {
        printf("P%d   %2d %2d  %2d   %2d  %2d  %2d  %2d\n", i+1, arr[i].prior, arr[i].at, arr[i].bt, ct[i], tat[i], wt[i], rt[i]);
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
    printf("Context switching: %d\n", count);
    return 0;
}