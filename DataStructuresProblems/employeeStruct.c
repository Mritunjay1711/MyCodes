#include <stdio.h>
#include <stdlib.h>

struct employee
{
    int empId;
    char name[20];
    int age;
    float salary;
};

void maxSalary(struct employee *e, int n)
{
    int maxSal = 0, index;
    for (int i = 0; i < n; i++)
    {
        if (maxSal < (e + i)->salary)
        {
            maxSal = (e + i)->salary;
            index = i;
        }
    }

    printf("The details of employee with maximum salary are\n");
    printf("Id: %d\n", (e + index)->empId);
    printf("Name: %s\n", (e + index)->name);
    printf("Age: %d\n", (e + index)->age);
    printf("Salary: %.2f\n", (e + index)->salary);
}

int main()
{
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    struct employee *e = (struct employee *)malloc(n * sizeof(struct employee));

    for (int i = 0; i < n; i++)
    {
        printf("Enter the details of employee %d\n", i + 1);
        printf("Id: ");
        scanf("%d", &(e + i)->empId);
        printf("Name: ");
        scanf(" %[^\n]", (e + i)->name);
        printf("Age: ");
        scanf("%d", &(e + i)->age);
        printf("Salary: ");
        scanf("%f", &(e + i)->salary);
    }

    // for (int i = 0; i < n; i++)
    // {
    //     printf("The details of employee %d are:\n", i + 1);
    //     printf("Id: %d\n", (e + i)->empId);
    //     printf("Name: %s\n", (e + i)->name);
    //     printf("Age: %d\n", (e + i)->age);
    //     printf("Salary: %.2f\n", (e + i)->salary);
    // }

    maxSalary(e, n);
    free(e);
    return 0;
}