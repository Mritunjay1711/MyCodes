#include<stdio.h>
#include<string.h>


struct people{
    char name[20];
    int age;
    char sex[10];
    int dob;
};

void mr_scanf(struct people *p)
{
    printf("Enter the name, age, sex and DOB(ddmmyyyy) of the person here:");
    scanf("%s %d %s %d",p->name,&p->age, p->sex, &p->dob);
}

void mr_print(struct people *p)    
{
    static int i = 0;
    i++;
    if(i <= 1)
    {
        printf("SI No.        Name          Age      sex      DOB\n");
    }
        printf("%d             %s          %d        %s       %d\n", i,p->name, p->age, p->sex, p->dob);
}

int main()
{
    struct people mr_p[6];
    struct people *p;
    p = mr_p;
    int mr_age = (2006226 % 10) + 10;
    for(int i = 0; i < 6; i++)
    {
        mr_scanf((p + i));
    }

     for(int i = 0; i < 6; i++)
    {
        if((p + i)->age > mr_age)
        {
            mr_print(p + i);
        }
    }


    return 0;
}