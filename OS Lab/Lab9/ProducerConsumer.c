#include<stdio.h>
#include<stdlib.h>

void wait(int *a){
    while(*a <= 0);
    (*a)--;
}

void signal(int *b){
    (*b)++;
}

void produce(int *s, int *e, int *f)
{
    wait(e);
    wait(s);
    printf("Item produced!\n");
    signal(s);
    signal(f);
}



void consume(int *s, int *e, int *f)
{
    wait(f);
    wait(s);
    printf("Item consumed!\n");
    signal(s);
    signal(e);
}

int main()
{
    int n;
    printf("Enter the value of buffer: ");
    scanf("%d", &n);
    int e = n, s = 1, f = 0;
    int a;
    do{
        printf("Enter\n1 to Produce\n2 to Consume\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            produce(&s, &e, &f);
            break;
        case 2:
            consume(&s, &e, &f);
            break;
        default:
            break;
        }
    }while(a);
    return 0;
}