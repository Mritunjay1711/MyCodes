#include<stdio.h>
#include<stdlib.h>

void wait(int *a)
{
    while(*a <= 0)
    ;
    (*a)--;
}

void signal(int *b)
{
    (*b)++;
}

void write(int *wrt)
{
    wait(wrt);
    printf("Executed write operation\n");
    signal(wrt);
}

void callReader(int *wrt, int *mutex, int *read_count)
{
    wait(mutex);
    (*read_count)++;
    if((*read_count) == 1)
        wait(wrt);
    printf("Reader arrived!\n");
    signal(mutex);
}

void sendReader(int *wrt, int *mutex, int *read_count)
{
    wait(mutex);
    while((*read_count)< 0);
    (*read_count)--;
    if((*read_count) == 0)
        signal(wrt);
    printf("Reader went!\n");
    signal(mutex);
}

int main()
{
    int wrt = 1;
    int read_count = 0;
    int mutex = 1;
    int a;
    do{
        printf("Enter\n1 to Call reader\n2 to send reader\n3 to writer\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            callReader(&wrt, &mutex, &read_count);
            break;
        case 2:
            sendReader(&wrt, &mutex, &read_count);
            break;
        case 3:
            write(&wrt);
            break;
        default:
            break;
        }
    }while(a);
    return 0;
}