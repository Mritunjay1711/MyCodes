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
    
}

int main()
{
    struct people mr_p[6];
    struct people *p;
    p = mr_p;

    for(int i = 0; i < 6; i++)
    {
        mr_scanf(p + i);
    }

    for(int i = 0; i < 6; i++)
    {
        if(!(strcmp((p + i)->sex, "Female") && strcmp((p + i)->sex, "female")))
        {
            mr_print(p + i);
        }
    }

    return 0;
}