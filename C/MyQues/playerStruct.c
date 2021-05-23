#include<stdio.h>
struct date{
    int dd;
    int mm;
    int yy;
};

struct player{
    char name[20];
    int age;
    struct date d;  
};

void scan(struct player *p)
{   
    printf("Enter the Name age and DOB(dd/mm/yy) of player:");
    scanf("%s %d %d/%d/%d", p->name, &p->age, &p->d.dd, &p->d.mm, &p->d.yy);
}

void print(struct player *p)
{
    static int i = 0;
    i++;
    if(i <= 1)
    {
        printf("SI No.        Name          Age           DOB\n");
    }
        printf("%d             %s          %d             %d/%d/%d\n", i,p->name, p->age, p->d.dd, p->d.mm, p->d.yy);
}


int main()
{
    struct player mr_p[7];
    struct player *mr_b;
    int mr_age = 26;
    mr_b = mr_p;
    for(int i = 0; i < 7; i++)
    {
        scan(mr_b + i);
    }

    for(int i = 0; i < 7; i++)
    {
        if((mr_b + i)->age > mr_age)
        {
            print(mr_b + i);
        }
    }

    return 0;
}

// abd 42 17/07/3
// koh  3 2/3/2
// b 43 2/3/4
// kdf 3 4/4/4
// sk 29 4/4/4
// shd 30 4/4/4
// kj 4 4/4/4