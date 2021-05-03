#include<stdio.h>
int main()
{
    int n=19;
    int *p=&n;
    int result=0;
    
    result=*p+n;
    printf("%i\n",result);
    printf("%p\n",p);
    printf("%d",sizeof(p)); 
    return 0;
}