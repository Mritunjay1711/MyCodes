#include<stdio.h>

int main()
{
    FILE *fp;
    int n[10], sum = 0;

    fp = fopen("nums.txt","r");
    for(int i = 0; i < 10; i++)
    {
        fscanf(fp,"%d",&n[i]);
        sum += n[i];
    }
    fclose(fp);
    printf("The sum of the numbers are %d\n",sum);
    return 0;
}           