#include<stdio.h>
int main(){
    /*This is a program to check if two kangaroo from a certain
    point and at a particular speed will catch each other
    on number line or not*/

    int x1,x2,v1,v2,i=1,a,b;
    scanf("%d %d %d %d",&x1,&v1,&x2,&v2);
    while (i>0)
    { a=x1+(i*v1);
      b=x2+(i*v2);
    if(a<b && v1<v2 )
    {
        printf("NO");
        break;
    }
    else if(a>b && v1>v2)
    {
        printf("NO");
        break;
    }
    else if (x1=x2)
     {
         printf("YES");
         break;
     } 
    else i++;
    }
     
    return 0;
}