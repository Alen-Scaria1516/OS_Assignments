#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>

#define FIFO_NAME "myfile.txt"

int main()
{
    char s[300];
    int num,fd;
    mkfifo(FIFO_NAME,0666);
    printf("Waiting for readers ..\n");
    fd = open(FIFO_NAME,O_WRONLY);
    printf("Got a reader-- type some stuff.\n");
    gets(s);

    if((num=write(fd,s,strlen(s)))==-1)
    {
        perror("write");
    }
    else 
    {
        printf("Writer wrote %d bytes\n",num);
        return 0;
    }
}