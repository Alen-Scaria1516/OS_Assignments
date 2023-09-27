#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

//initialising variable for mutex and conditional variable 
pthread_mutex_t mutexFuel;
pthread_cond_t condFuel;
int fuel = 0;

void *fuel_filling_station(void *arg)
{
    //at a time 5 buckets are being filled 
    for (int i = 0; i < 5; i++)
    {
        //locking the mutex for preventing race condition 
        pthread_mutex_lock(&mutexFuel);
        fuel += 60;
        printf("Filled fuel %d\n", fuel);
        pthread_mutex_unlock(&mutexFuel);
        pthread_cond_signal(&condFuel);//will wake only one thread
        //pthread_cond_broadcast(&condFuel);//will wake all the threads 
        sleep(1);//giving a delay for the signal to pass
    }
}

void *car_filling(void *arg)
{
    pthread_mutex_lock(&mutexFuel);
    while (fuel < 40)
    {
        printf("No fuel \n");
        // sleep(1);
        pthread_cond_wait(&condFuel, &mutexFuel);
    }
    fuel -= 40;
    printf("Got Fuel.Now left: %d \n", fuel);
    pthread_mutex_unlock(&mutexFuel);
}
int main(int argc, char *argv[])
{
    pthread_t th[5];//we are using 5 threads 
    pthread_mutex_init(&mutexFuel, NULL);
    pthread_cond_init(&condFuel, NULL);
    for (int i = 0; i < 5; i++)
    {
        //when i = 4 we are filling the station 
        if (i == 4)
        {
            //pthread_create returns 0 if successful
            if (pthread_create(&th[i], NULL, &fuel_filling_station, NULL) != 0)
            {
                perror("Failed to create thread\n");
            }
        }
        else
        {
            if (pthread_create(&th[i], NULL, &car_filling, NULL) != 0)
            {
                perror("Failed to create thread\n");
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        //pthread_join is used to terminate the thread
        if (pthread_join(th[i], NULL) != 0)
        {
            perror("Failed to join thread\n");
        }
    }
    //closing the  mutex and conditional variables
    pthread_mutex_destroy(&mutexFuel);
    pthread_cond_destroy(&condFuel);
    return 0;
}