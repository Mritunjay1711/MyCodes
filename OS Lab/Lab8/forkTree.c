#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>

int main() {
pid_t c1,c2,c3,c4,c5,c6;
//for child1
c1=fork();
    if(c1 == 0)
    {
//for grandchild4
        c4=fork();
        if(c4 == 0)
        {
            printf("c4:- pid: %d, ppid: %d\n", getpid(), getppid());
        }
        else
        {
        printf("\nc1:- pid: %d, ppid: %d\n", getpid(), getppid());
        sleep(3);
        }
    }
    else
    {
    //for child2
        c2=fork();
        if(c2 == 0)
        {
            //for grandchild5
            c5=fork();
            if(c5 == 0)
            {
            printf("\nc5:- pid: %d, ppid: %d\n", getpid(), getppid());
            }
            else
            {
            printf("\nc2:- pid: %d, ppid: %d\n", getpid(), getppid());
            sleep(3);
            }
        }
        else 
        {
            //for child3
            c3=fork();
            if(c3 == 0) {
                //for grandchild6
                c6=fork();
                if(c6 == 0)
                {
                printf("\nc6:- pid: %d, ppid: %d\n", getpid(), getppid());
                }
                else
                {
                printf("\nc3:- pid: %d, ppid: %d\n", getpid(), getppid());
                sleep(3);
               }
            }
            else
            {
            printf("\nP:- pid: %d, ppid: %d\n", getpid(), getppid());
            sleep(3);
            }
        }
            sleep(3);
    }
return 0;
}