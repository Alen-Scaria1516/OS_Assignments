#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t p = fork();

    if(p==-1)
    {
        perror ("fork");
        exit(1);

    }
    if(p==0)
    {
        printf("Child is created\n");
        printf("The PID i s%d\n",getpid());

    }
    else{
        waitpid(p,0,0);
        printf("The parent PID is %d\n",getppid());
        sleep(10);
        exit(0);
    }
    return 0;
}