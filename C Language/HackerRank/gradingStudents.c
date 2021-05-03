#include<stdio.h>
int main(){
    int n,marks[60],a;

    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&marks[i]);
    }

    for(int i=0;i<n;i++)
   {
       a=marks[i]/5;
       a=(a+1)*5;
       if((a-marks[i])<3 && marks[i]>37)
          marks[i]=a;
        else marks[i]=marks[i];
       
   }
   for(int i=0;i<n;i++)
   {
       printf("%d\n",marks[i]);
   }
    return 0;
}