#include <stdio.h>
#include <pthread.h>

int primes[10] = {2, 3, 7, 11, 13, 17, 19, 23, 29};

void *routine(void *arg)
{
    int prime = *(int *)arg;
    printf("%d ", prime);
    pthread_exit(NULL);
}

int main()
{
    pthread_t th[10];
    for (int i = 0; i < 10; i++)
    {
        if (pthread_create(&th[i], NULL, &routine, &primes[i]) != 0)
            [return 1;
            ]
    }
    for (int i = 0; i < 10; i++)
    {
        if (pthread_join(&th[i], NULL) != 0)
            [return 2;
            ]
    }
    return 0;
}