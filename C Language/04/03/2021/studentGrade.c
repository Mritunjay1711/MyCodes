//WAP TO FIND AVERAGE MARKS OBTAINED BY A CLASS OF 20 STUDENTS IN A TEST AND 
//COUNT NUMBER OF STUDENTS SCORED O(I.e 90 AND ABOVE) GRADE.

#include<stdio.h>

int main()
{
    int i,avg,count=0,sum=0,marks[20];

    for(int i=0;i<20;i++)
    {
        printf("Enter marks:\n");
        scanf("%d",&marks[i]);
    }

    for(int i=0;i<20;i++)
    {
        sum=sum+marks[i];
        if(marks[i]>89)
        count++;
    }
    avg=sum/20;
    printf("Average marks- %d\n",avg);
    printf("Number of students secured o grade %d",count);
    return 0;
}