#include<stdio.h>
#include<stdlib.h>

struct student
{
    int roll;
    int age;
    float cgpa;
    char sub[20]; 
};

int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct student *s = (struct student*)malloc(n * sizeof(struct student));

    for(int i = 0; i < n; i++)
    {
        printf("Enter the details of student %d\n", i + 1);
        printf("Roll: ");
        scanf("%d", &(s+i)->roll);
        printf("Age: ");
        scanf("%d", &(s+i)->age);
        printf("Cgpa: ");
        scanf("%f", &(s+i)->cgpa);
        printf("Subject: ");
        scanf(" %[^\n]", (s+i)->sub);
    }

    for(int i = 0; i < n; i++)
    {
        printf("The details of student %d are:\n", i + 1);
        printf("Roll: %d\n", (s + i)->roll);
        printf("Age: %d\n", (s + i)->age);
        printf("Cgpa: %.2f\n", (s + i)->cgpa);
        printf("Subject: %s\n", (s + i)->sub);
    }

    free(s);
    return 0;
}