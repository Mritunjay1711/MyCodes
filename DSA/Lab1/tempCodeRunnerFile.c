
#include<stdlib.h>

struct Student{
    int roll;
    char name[20];
    float cgpa;
};

int main()
{
    struct Student *s = (struct Student*)malloc(sizeof(struct Student));
    printf("Enter the details of Student\n");
    printf("Roll: ");
    scanf("%d", &s->roll);
    printf("Name: ");
    scanf(" %[^\n]", s->name);
    printf("CGPA: ");
    scanf("%f", &s->cgpa);

    printf("Details of Student\n");
    printf("Roll: %d\n", s->roll);
    printf("Name: %s\n", s->name);
    printf("CGPA: %.2f\n", s->cgpa);
    
    free(s);
    return 0;
}