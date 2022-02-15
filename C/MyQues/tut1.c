#include <Stdio.h>

// int main(){

//     char num = 130;
//     num += 1;
//     printf("%d", (unsigned char)num);
//     num = 130;
//     printf("\n%d",(char)(num + 1));
//     return 0;
// }

// union stu{
//     int a;
//     char b[2];
// };
// union stu no = {333};
// int main()
// {
//     no.b[0] = 0;
//     printf("%d",no.a);
// }

// int main()
// {
//     {
//         int x = 2;
//     }

//     {
//         printf("%d\n",x);
//     }
//     int x = 6;
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
int main()
{

    int i;
    int *p = (int *)malloc(5 * sizeof(int));

    for (i = 0; i < 5; i++)
        *(p + i) = i;

    
    for(i = 0; i < 5; i++)
        printf("%d ", p[i]);
    printf("\n");
    printf("%d \n", *p++);
    for(i = 0; i < 5; i++)
        printf("%d ", p[i]);
    printf("\n");
    printf("%d \n", (*p)++);
    for(i = 0; i < 5; i++)
        printf("%d ", p[i]);
    printf("\n");
    printf("%d \n", *p);
    for(i = 0; i < 5; i++)
        printf("%d ", p[i]);
    printf("\n");
    printf("%d \n", *++p);
    for(i = 0; i < 5; i++)
        printf("%d ", p[i]);
    printf("\n");
    printf("%d \n", ++*p);
    printf("\n");
    for(i = 0; i < 5; i++)
        printf("%d ", p[i]);
    return 0;
}