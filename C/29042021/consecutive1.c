#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, *ptr, old_pos = -1, old_count = 0, new_count = 0, new_pos = 0;

    printf("Enter the number of elements: ");
    scanf("%d",&n);

    ptr = (int*)malloc(n * sizeof(int));

    printf("Enter the 0 and 1: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }

    for(int i = 0; i < n; i++)
    {
        if(!ptr[i])
        {
            new_count = 0;
            new_pos = i + 1;
        }
        if(ptr[i])
        {
            new_count++;
            if(new_count > old_count)
            {
                old_count = new_count;
                old_pos = new_pos;
            }
        }
    }

    printf("The most occurence of 1 is at %d position and  %d times.\n", old_pos + 1, old_count + 1);
    return 0;
}