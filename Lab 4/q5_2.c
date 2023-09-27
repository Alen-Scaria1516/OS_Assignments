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

int main(void)
{
    char s[300];
    int num,fd;
    mkfifo(FIFO_NAME,0666);
    printf("Waiting for writers ... \n");
    fd = open(FIFO_NAME,O_RDONLY);
    printf("Got a writer ... \n");

    if((num == read(fd,s,300))==-1)
    {
        perror("read");
    }
    else{
        s[num] = '\0';
        printf("Reader read %d bytes : %s\n",num,s);

    }
    return 0;
}