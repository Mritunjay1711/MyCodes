#include<stdio.h>

struct cricket{
    char player_name[20];
    char team_name[20];
    float batting_average;
};

int main()
{
    struct cricket c[5], a;
    
    for(int i = 0; i < 5; i++)
    {
        scanf("%s %s %f", c[i].player_name, c[i].team_name, &c[i].batting_average);
    }
    
    for(int i = 0; i < 5; i++)
    {
        for(int j = i + 1; j < 5; j++)
        {
            if(c[i].batting_average < c[j].batting_average)
            {
                a = c[i];
                c[i] = c[j];
                c[j] = a;
            }
        }
        
    }
    
    for(int i = 0; i < 5; i++)
    {
        printf("%s %s %.2f\n", c[i].player_name, c[i].team_name, c[i].batting_average);
    }

    return 0;
}