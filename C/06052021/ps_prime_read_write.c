#include<stdio.h>

int prime(int n)
{
    int flag = 1;
    for(int i = 2; i < n; i++)
    {
        if(n % i == 0)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

void convertNum(int num)
{
    
    char *onedigit[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char *twodigit[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    char *multipleten[] = {" "," ","twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};;
    int temp = num/100;
    printf("%s hundred ",onedigit[temp - 1]);
    int temp2 = num % 100;
    if((temp2 < 19) && (temp2 > 9))
    {
        printf("%s\n ",twodigit[(temp2 % 10)]);
    }
    else if(temp2 > 19)
    {
        int temp3 = temp2/10;
        printf("%s ",multipleten[temp3]);
        printf("%s\n",onedigit[(temp2 % 10) - 1]);
    }
}


int main()
{
    FILE *fp1, *fp2;
    fp1 = fopen("primedata.txt","r");
    fp2 = fopen("prime.txt", "w");
    int arr[50], t = 0;
    char ch,*k;
    while((ch = fgetc(fp1)) != EOF)
    {
        fscanf(fp1, "%d", &arr[t]);
       
        if(prime(arr[t]))
        {
            printf("%d ",arr[t]);
            fprintf(fp2,"%d ",arr[t]);
            convertNum(arr[t]);
        }
        t++;
    }
    printf("\n");
    fclose(fp1);
    fclose(fp2);
    return 0;
}