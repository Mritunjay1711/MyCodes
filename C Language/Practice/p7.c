//Pointer arithmetic

// *valuePtr    can be used to access the first integer of the values array, that is,values[0]
 /* To reference to values[3] through valuesPtr variable, we can add 3 to 
     valuesPtr and then apply the indirection operator 
     *(valuesPtr+3)   */

    /* The expression, *(valuesPtr+i) can be used to access the value contained in values[i]
        e.g to set values[10]=27, we can use 
        values[10]=27;
        or
        *(valuesPtr+10)=27;       */

     /*  using the increment operator on a pointer has the same effect as adding one to __SIZEOF_POINTER_
       using the decrement operator has the same effect as subtracting one from pointer
     ++valuesPtr;       
     sets valuesPtr pointing to the next integer in the values array (values[1])

     --textPtr;                          
     sets the valuesPtr pointing to the previous integer in the values array, assuming that valuesPtr 
     was not pointing to the beginining of the values array.                         
     */
     
     #include<stdio.h>
     
     int arraySum(int array[],const int n)
     {
         int sum=0,*ptr;
         int *const arrayEnd=array+n;

         for(ptr=array; ptr < arrayEnd; ++ptr)
         sum+=*ptr;

         return sum;
     }

     void main(void)
     {
         int arraySum(int array[],const int n);
         int values[10]={2,5,2,6,7,23,19,20,26,17};

         printf("The sum is %i\n",arraySum(values,10));
     }