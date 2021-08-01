#include <stdio.h>

struct student
{
    char name_201[20];
    float marks_201[5], perc_201, tot_201;
    int rollno_201;
};

void totperc(struct student s_201[], int n_201)
{
    for (int i_201 = 0; i_201 < n_201; i_201++)
    {
        s_201[i_201].tot_201 = 0;
        for (int j_201 = 0; j_201 < 5; j_201++)
        {
            s_201[i_201].tot_201 = s_201[i_201].tot_201 + s_201[i_201].marks_201[j_201];
        }
        s_201[i_201].perc_201 = s_201[i_201].tot_201 / 5;
    }
}

void find(struct student s_201[], int n_201, int min_201, int max_201)
{
    for (int i_201 = 0; i_201 < n_201; i_201++)
    {
        if (s_201[i_201].perc_201 >= min_201 && s_201[i_201].perc_201 <= max_201)
        {
            printf("\nName of the student - %s", s_201[i_201].name_201);
            printf("\nRoll no. of the student - %d", s_201[i_201].rollno_201);
            for (int j_201 = 0; j_201 < 5; j_201++)
            {
                printf("\nMarks of subject %d of the student - ", j_201 + 1);
                printf("\n%f", s_201[i_201].marks_201[j_201]);
            }
            printf("\nTotal marks - %f", s_201[i_201].tot_201);
            printf("\nPercentage - %f", s_201[i_201].perc_201);
        }
    }
}

int main()
{
    int n_201, min_201, max_201;
    printf("Enter the number of students - ");
    scanf("%d", &n_201);
    struct student s_201[n_201], temp_201;
    for (int i_201 = 0; i_201 < n_201; i_201++)
    {
        printf("Enter name of the student - ");
        scanf("%s", s_201[i_201].name_201);
        printf("Enter roll no. of the student - ");
        scanf("%d", &s_201[i_201].rollno_201);
        for (int j_201 = 0; j_201 < 5; j_201++)
        {
            printf("Enter marks of subject %d of the student - ", j_201 + 1);
            scanf("%f", &s_201[i_201].marks_201[j_201]);
        }
    }
    totperc(s_201, n_201);
    for (int i_201 = 0; i_201 < n_201 - 1; i_201++)
    {
        for (int j_201 = 0; j_201 < n_201 - i_201 - 1; j_201++)
        {
            if (s_201[i_201].tot_201 > s_201[i_201 + 1].tot_201)
            {
                temp_201 = s_201[i_201];
                s_201[i_201] = s_201[i_201 + 1];
                s_201[i_201 + 1] = temp_201;
            }
        }
    }
    printf("\nEnter the range of percentage - ");
    scanf("%f %f", &min_201, &max_201);
    find(s_201, n_201, min_201, max_201);

    for (int i_201 = 0; i_201 < n_201; i_201++)
    {
        printf("\nName of the student - %s", s_201[i_201].name_201);
        printf("\nRoll no. of the student - %d", s_201[i_201].rollno_201);
        for (int j_201 = 0; j_201 < 5; j_201++)
        {
            printf("\nMarks of subject %d of the student - ", j_201 + 1);
            printf("\n%f", s_201[i_201].marks_201[j_201]);
        }
        totperc(s_201, n_201);
        printf("\nTotal marks - %f", s_201[i_201].tot_201);
        printf("\nPercentage - %f", s_201[i_201].perc_201);
    }
    return 0;
}