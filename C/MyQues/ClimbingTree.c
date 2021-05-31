#include<stdio.h>

// Function to find nth fibonacci number
int fib(int n)
{
	if (n <= 1)
		return n;
	return fib(n - 1) + fib(n - 2);
}

// Function to find the ways of Steve as his step size is 1, 2 and 3.
int findStepSteve(int n)
{
	if (n == 1 || n == 0)
		return 1;
	else if (n == 2)
		return 2;

	else
		return findStepSteve(n - 3) + findStepSteve(n - 2) + findStepSteve(n - 1);
}

// Function to find the ways of mark as his step size is 1 and 2.
int findStepMark(int n)
{
	return fib(n + 1);
}

// Main code
int main()
{
    int n, steve, mark;
    scanf("%d",&n);

    steve = findStepSteve(n);
    mark = findStepMark(n);

    printf("Steve Waugh = %d\n", steve);
    printf("Mark Waugh = %d", mark);

    return 0;
}