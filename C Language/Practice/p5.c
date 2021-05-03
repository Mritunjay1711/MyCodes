// long value=99L;
// const long *pvalue=&value;     defining a pointer to constant

//*pvalue=888L  ERROR!
//But we can change (value) but cannot use pointer to change




//NOT ALLOWING THE ADDRESS STORED TO CHANGE

//int count=43;
// int *const pcount=&count;   //Defines a constant pointer


//The above assures that a pointer always points to the same thing
//indicates that the address stored must not be changed

// int item=34;
// pcount=&item;    //Error= attemp to change a constant pointer



/****************************************************************************
 It is all about 

 const int*........    //value can not be changed
 int *const .......    // pointer address cannot change
 ***************************************************************************/
