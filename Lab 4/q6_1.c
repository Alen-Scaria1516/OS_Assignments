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

    printf("Waiting for readers...\n");
    fd1= open(FIFO_NAME1,O_WRONLY);
    fd2= open(FIFO_NAME2,O_WRONLY);

    printf("Got a reader. type some stuff...\n");
    gets(s1);
    gets(s2);

    if((num1=write(fd1,s1,strlen(s1)))==-1)
    {
        perror("write");
    }
    else 
    {
        printf("Writer wrote %d bytes\n",num1);
    }

    if((num2=write(fd2,s2,strlen(s2)))==-1)
    {
        perror("write");
    }
    else{
        printf("Writer wrote %d bytes\n",num2);
    }
    return 0;


}