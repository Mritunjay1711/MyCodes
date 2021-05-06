#include<stdio.h>

struct time
{
    int hour;
    int minutes;
    int seconds;
    
};

void scan(struct time *t)
{
    scanf("%d:%d:%d", &t->hour, &t->minutes, &t->seconds);
}

void print(struct time t)

{
    printf("%d:%d:%d\n", t.hour, t.minutes, t.seconds);
}

struct time update (struct time *t)
{
    t->seconds += 1;
    if(t->seconds > 59)
    {
        t->minutes += 1;
        t->seconds = 0;
    }
    if(t->minutes > 59)
     {
         t->hour += 1;
         t->minutes = 0;
     }   
    if(t->hour > 23)
     {
         t->hour = 00;
     }   

     return(*t);
}

int main()
{
    struct time t;
    struct time *ptr;
    ptr = &t;
    printf("Enter the time in format hh:mm:ss ");
    scan(ptr); 
    update(ptr);
    print(t);
    return 0;
}