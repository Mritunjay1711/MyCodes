// This program will take input from user and check whether the input is correct date or not.


#include<stdio.h>

struct date 
{
    int day;
    int month;
    int year;
};

int check(struct date *d)
{
    static int flag;
    if(!(d->year % 4) || (!(d->year % 400) && !(d->year % 100)))
    {
        flag = 1;
    }


    static int month;

    if((d-> month == 1) || (d-> month == 3) || (d-> month == 5) || (d-> month == 7) || (d-> month == 8) || (d-> month == 10) || (d-> month == 12))
    {
        if((d->day >= 1) && (d->day <= 31))
        month = 1;
    }
    else if((d->month == 4) || (d->month == 6) || (d->month == 9) || (d->month == 11))
    {
        if((d->day >=1) && (d->day <= 30))
        month = 1;
    }
    else if(d->month == 2)
    {
        if(flag==1 && ((d->day >= 1) && (d->day <= 29)))
        {
            month = 1;
        }
        else if((d->day >= 1) && (d->day <= 28))
        month = 1;
    }


    return(month);
}


void scan(struct date *t)
{
    scanf("%d:%d:%d", &t->day, &t->month, &t->year);
}


void print(struct date t)
{
    printf("%d:%d:%d\n", t.day, t.month, t.year);
    switch(t.month)
    {
        case 1:
            printf("January %d, %d\n",t.day, t.year);
            break;
        case 2:
            printf("February %d, %d\n",t.day, t.year);
            break;
        case 3:
            printf("March %d, %d\n",t.day, t.year);
            break;
        case 4:
             printf("April %d, %d\n",t.day, t.year);
            break;
        case 5:
           printf("May %d, %d\n",t.day, t.year);
            break;
        case 6:
             printf("June %d, %d\n",t.day, t.year);
            break;
        case 7: 
            printf("July %d, %d\n",t.day, t.year);
            break;
        case 8:
            printf("August %d, %d\n",t.day, t.year);
            break;
        case 9:
            printf("September %d, %d\n",t.day, t.year);
            break;
        case 10:
            printf("October %d, %d\n",t.day, t.year);
            break;
        case 11:
            printf("November %d, %d\n",t.day, t.year);
            break;
        case 12:
            printf("December %d, %d\n",t.day, t.year);
            break;
             
    }   
}



int main()
{
    struct date d;
    struct date *ptr;
    ptr = &d;
    
    printf("Enter the date in dd:mm:yyyy format: ");
    scan(ptr);
    int m = check(ptr);
    
    if(m)
    print(d);
    else
    printf("INVALID INPUT!\n");
  
    return 0;
}