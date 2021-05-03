#include<stdio.h>

int main(){
    int a=8;
    float f=78.768678687678687;
    double d=78.768678687678687;
    char c='M';
    
    printf("%d\n",sizeof(a));
    printf("%d\n",sizeof(f)); 
    printf("%d\n",sizeof(d));
    printf("%d\n",sizeof(c));
    return 0;
}