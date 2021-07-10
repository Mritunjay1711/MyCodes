#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct triangle{
    int a;
    int b;
    int c;
};

float area(struct triangle *s)
{
    float p = (s->a + s->b + s->c)/2.0;
    float area = sqrt(p*(p-s->a)*(p-s->b)*(p-s->c));
    return area;
}

int main()
{
    struct triangle *s = (struct triangle*)malloc(sizeof(struct triangle));
    s->a = 22;
    s->b = 18;
    s->c = 5;
    printf("%d\n", area(s));
    
    return 0;
}