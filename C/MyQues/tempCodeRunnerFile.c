int mr_fibonacci(int n)
{
    int mr_n1 = 0, mr_n2 = 1, mr_nextnum = mr_n1 + mr_n2;
    if(n == 1)
    return 0;
    if(n == 2)
    return 1;
    if(n ==3)
    return 1;
    else
    {
        while(n - 3)
        {

            mr_n1 = mr_n2;
            mr_n2 = mr_nextnum;
            mr_nextnum = mr_n1 + mr_n2;
            n--;
        }
    }
      
    return mr_nextnum;
}