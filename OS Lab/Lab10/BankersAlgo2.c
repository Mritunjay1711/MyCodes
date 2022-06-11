#include<stdio.h>
#include<stdlib.h>


int main()
{
    
        int alloc[3][3] = {{0, 0, 1}, {3, 2, 0}, {2, 1, 1}};
        int max[3][3] = {{8, 4, 3}, {6, 2, 0}, {3, 3, 3}}, need[3][3];
        int avail[3] = {3, 2, 2};
        int req[3], rn;
        printf("Enter the req: ");
        scanf("%d%d%d", &req[0], &req[1], &req[2]);
        printf("Enter the process no: ");
        scanf("%d", &rn);
        for(int i = 0;  i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                need[i][j] = max[i][j] - alloc[i][j];
            }
        }
        for(int j = 0; j < 3; j++)
        {
            need[rn][j] -= req[j];
            alloc[rn][j] += req[j];
            avail[j] -= req[j];
        }
        printf("Need matrix\n");
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                printf("%d ", need[i][j]);
            }
            printf("\n");
        }
        int proc[3] = {1, 1, 1};
        int temp, flag;
        for(int i = 0; i < 3; i = (i + 1) % 3)
        {
            out:
            // if(temp == i)
            // {
            //     printf("Deadlock!");
            //     break;
            // }
            // printf("%d %d %d %d => Proc\n", proc[0], proc[1], proc[2], proc[3]);
            if(proc[i] == 1){
                for(int j = 0; j < 3; j++)
                {
                    if(need[i][j] > avail[j])
                    {
                        // temp = i;
                        i = (i + 1)%3;
                        goto out;
                    }
                }
                // temp = i;
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
            for(int i = 0; i < 3; i++)
            {
                if(proc[i] != 0)
                    flag = 1;
            }
            if(!flag)
                break;
        }


    return 0;
}