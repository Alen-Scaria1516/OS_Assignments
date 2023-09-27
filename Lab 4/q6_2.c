#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FIFO_NAME1 "myfile1.txt"
#define FIFO_NAME2 "myfile2.txt"

int main(void)
{
    char s1[300];
    char s2[300];
    int num1,fd1;
    mkfifo(FIFO_NAME1,0666);

    int num2,fd2;
    mkfifo(FIFO_NAME2,0666);

    printf("Waiting for writers ...\n");

    fd1 = open(FIFO_NAME1,O_RDONLY);
    fd2 = open(FIFO_NAME2,O_RDONLY);

    printf("Got a writer ...\n");

    if((num1= read(fd1,s1,300))==-1)
    {
        perror("read");
    }
    else{
        s1[num1] = '\0';
        printf("Reader read %d bytes: %s\n",num1,s1);
    }

    if((num2= read(fd2,s2,300))==-1)
    {
        perror("read");
    }
    else{
        s2[num2] = '\0';
        printf("Reader read %d bytes: %s\n",num2,s2);
    }
    return 0;


}