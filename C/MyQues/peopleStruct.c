#include<stdio.h>
#include<string.h>


struct people{
    char name[20];
    int age;
    char sex[10];
    int dob;
};

void mj_scanf(struct people *p)
{
    printf("Enter the name, age, sex and DOB(ddmmyyyy) of the person here:");
    scanf("%s %d %s %d",p->name,&p->age, p->sex, &p->dob);
}

void mj_print(struct people *p)
{
    static int i = 0;
    i++;
    if(i <= 1)
    {
        printf("SI No.        Name          Age        DOB\n");
    }
        printf("%d             %s            %d         %d\n", i,p->name, p->age, p->dob);
}

int main()
{
    struct people mj_p[5];
    struct people *p;
    p = mj_p;
    for(int i = 0; i < 5; i++)
    {
        mj_scanf((p + i));
    }

     for(int i = 0; i < 5; i++)
    {
        if(!(strcmp(((p + i)->sex),"female")))
        {
            mj_print(p + i);
        }
    }


    return 0;
}