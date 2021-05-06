#include<stdio.h>

int main()
{
    FILE *fp;
    int a[10] = {83, 92, 18, 29, 387, 23, 91, 832, 34};
    fp = fopen("output.txt","w");

    for(int i = 0; i < 10; i++)
    {
        fprintf(fp, "%d ", a[i]);
    }
    fclose(fp);
    return 0;
}