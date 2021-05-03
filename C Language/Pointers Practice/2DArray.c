#include<stdio.h>
int main()
{
    int b[4][3]={5,9,1,7,2,0,3,4,6,8,2,7};
    //HEre &b is address of array
    //b is address of first row
    //*b is address of first element
    //**b is the first element
    //b+1 is the address of second row

    printf("The first and second element of first row are %i and %i\n",**b,*(*b+1));
    printf("The first and second element of second row are %i and %i\n",**(b+1),*(*(b+1)+1));
}