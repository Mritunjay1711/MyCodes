#include<stdio.h>
#include<stdlib.h>

typedef struct date
{
    int day, month, year;
}date;

void swap(date *d1, date *d2)
{
    date temp = *d1;
    *d1 = *d2;
    *d2 = temp;
}

void printDate(date *d, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("Date[%d]: %d %d %d\n", i, d[i].day, d[i].month, d[i].year);
    }
}

void BubbleSort(date *d, int n)
{
    int flag;
    for(int i = 0; i < n - 1; i++)
    {
        flag = 0;
        for(int j = 0; j < n - i - 1; j++)
        {
            if(d[j].year > d[j + 1].year)
            {
                swap(&d[j], &d[j+1]);
                flag = 1;
            }
            else if(d[j].year == d[j+1].year && d[j].month > d[j+1].month)
            {
                swap(&d[j], &d[j+1]);
                flag = 1;
            }    
            else if(d[j].month == d[j + 1].month && d[j].day > d[j+1].day)
            {
                swap(&d[j], &d[j+1]);
                flag = 1;
            }
            
        }
        if(!flag)
            break;
    }
}

int main()
{
    int n;
    printf("Enter the number of dates: ");
    scanf("%d", &n);
    date *d = (date*)malloc(n * sizeof(date));
    for(int i = 0; i < n; i++)
    {
        printf("Enter the data for date[%d] in dd mm yyyy format: ", i);
        scanf("%d%d%d", &d[i].day, &d[i].month, &d[i].year);
    }

    printf("Before sorting: \n");
    printDate(d, n);
    BubbleSort(d, n);
    printf("After sorting:\n");
    printDate(d, n);
    return 0;
}