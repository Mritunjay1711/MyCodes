#include<stdio.h>
#include<stdlib.h>


int main()
{
    int *roll;
    char *name;
    float *cgpa;
    roll = (int*)malloc(sizeof(int));
    name = (char*)malloc(20 * sizeof(char));
    cgpa = (float*)malloc(sizeof(float));

    printf("Enter the roll: ");
    scanf("%d", roll);
    printf("Enter the name: ");
    scanf(" %[^\n]", name);
    printf("Enter the cgpa: ");
    scanf("%f", cgpa);

    printf("Roll: %d\n", *roll);
    printf("Name: %s\n", name);
    printf("CGPA: %.2f\n", *cgpa);

    free(roll);
    free(name);
    free(cgpa);
    return 0;
}