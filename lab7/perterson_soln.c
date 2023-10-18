#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int turn = 0;
int flag[2] = {0,0};
void * process0()
{
    while(1)
    {
        flag[0]= 1;
        turn = 1;
        while(flag[1] && turn ==1);

        //entering critical section
        printf("Process 0 in critical section.\n");
        

        //exit critical section
        flag[0]=0;
        printf("Process 0 exits critical section.\n");
        sleep(1);
    }
}


void * process1()
{
    while(1)
    {
        flag[1]= 1;
        turn = 0;
        while(flag[0] && turn ==0);

        //entering critical section
        printf("Process 1 in critical section.\n");
        
        //exit critical section
        flag[0]=0;
        printf("Process 1 exits critical section.\n");
        sleep(1);
    }
}


int main()
{
    pthread_t t1,t2;

    if(pthread_create(&t1,NULL,&process0,NULL)!=0)
    {
        return 1;
    }
    if(pthread_create(&t2,NULL,&process1,NULL)!=0)
    {
        return 2;
    }

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    return 0;
}