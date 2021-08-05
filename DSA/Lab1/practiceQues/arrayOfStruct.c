#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int roll;
    float cgpa;
    int age;
};

int main()
{
    struct Student *s = (struct Student*)malloc(2 * sizeof(struct Student));
    //Struct student *s[2] 
    // for(int i = 0; i < 2; i++)
    // {
    //     s[i] = (struct Student*)malloc(sizeof(struct Student));
    // }
    for (int i = 0; i < 2; i++)
    {
        printf("Enter the details of Student%d\n", i);

        printf("Enter  Roll no\n ");
        scanf("%d", &(s + i)->roll);
        printf("Enter the cgpa\n ");
        scanf("%f", &(s + i)->cgpa);
        printf("Enter the age\n ");
        scanf("%d", &(s + i)->age);
    }
    //    for(int i=1;i<=2;i++)
    // {
    //     printf(" the details of Student are %d\n",i);

    //     printf("%d", s[i]->roll );

    //     printf("%s", s[i]->sub);

    //     printf("%f", s[i]->cgpa);

    //     printf("%d", s[i]->age );

    // }
    //     free(s);
    return 0;
}