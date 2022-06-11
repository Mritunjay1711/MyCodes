#include<stdio.h>
#include<stdlib.h>


int main()
{
    int alloc[4][3] = {{1, 0, 1}, {1, 1, 2}, {1, 0, 3}, {2, 0, 0}};
    int max[4][3] = {{4, 3, 1}, {2, 1, 4}, {1, 3, 3}, {5, 4, 1}}, need[4][3];
    int avail[3] = {3, 3, 0};

    for(int i = 0;  i < 4; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    printf("Need matrix\n");
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    int proc[4] = {1, 1, 1, 1};
    int flag;
    for(int i = 0; i < 4; i = (i + 1) % 4)
    {
        out:
        // printf("%d %d %d %d => Proc\n", proc[0], proc[1], proc[2], proc[3]);
        if(proc[i] == 1){
            for(int j = 0; j < 3; j++)
            {
                if(need[i][j] > avail[j])
                {
                    i = (i + 1)%4;
                    goto out;
                }
            }
            for(int j = 0; j < 3; j++)
            {
                avail[j] -= need[i][j];
                avail[j] += max[i][j];
                proc[i] = 0;
            }
            printf("P%d finished execution\n", i);
            printf("Current avail: %d %d %d\n", avail[0], avail[1], avail[2]);
        }
        
        flag = 0;
        for(int i = 0; i < 4; i++)
        {
            if(proc[i] != 0)
                flag = 1;
        }
        if(!flag)
            break;
    }
    return 0;
}