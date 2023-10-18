#include<stdio.h> 
#include<stdlib.h> 
#include<errno.h> 
#include<string.h> 
#include<fcntl.h> 
#include<sys/types.h> 
#include<sys/stat.h> 
#include<unistd.h> 
#define FIFO_NAME1 "myfile1.txt" 
#define FIFO_NAME2 "myfile2.txt" 
 
int main(void) 
{ 
char s[300]; 
int fd1;  
mkfifo(FIFO_NAME1, 0666); 
int fd2;  
mkfifo(FIFO_NAME2, 0666); 
printf("waiting for response...\n"); // will create two pipes for two way 
communication 
fd1 = open(FIFO_NAME1, O_WRONLY); 
fd2 = open(FIFO_NAME2, O_RDONLY); 
printf("got a response--type some stuff\n"); 
int flag = 0; 
do 
{ int num1,num2; char s1[300],s2[300];  
gets(s1); 
 
if((num1 = write(fd1,s, strlen(s))) == -1) 
perror("write"); 
else 
printf("Write wrote %d bytes\n",num1); 
 
if((num2 = read(fd2,s,300)) == -1) 
perror("read"); 
else{ 
s[num2]= '\0'; 
printf("Reader read %d bytes\n",num2);} 
if(s1 == 'exit') 
flag = 1; 
} while(flag != 1); 
return 0; 
} 

/* part 2*/
#include<stdio.h> 
#include<stdlib.h> 
#include<errno.h> 
#include<string.h> 
#include<fcntl.h> 
#include<sys/types.h> 
#include<sys/stat.h> 
#include<unistd.h> 
#define FIFO_NAME1 "myfile1.txt" 
#define FIFO_NAME2 "myfile2.txt" 
 
int main(void) 
{ 
char s[300]; 
int fd1;  
mkfifo(FIFO_NAME1, 0666); 
int fd2;  
mkfifo(FIFO_NAME2, 0666); 
printf("waiting for message...\n"); 
fd1 = open(FIFO_NAME1, O_WRONLY); 
fd2 = open(FIFO_NAME2, O_RDONLY); 
printf("got a message--\n"); 
int flag = 0; 
do 
{ 
int num1,num2; char s1[300],s2[300];  
 
 
if((num2 = read(fd1,s,300)) == -1) 
perror("read"); 
else{ 
s[num2]= '\0'; 
printf("Reader wrote %d bytes\n",num2);} 
gets(s1); 
if(s1 == 'exit') 
flag = 1; 
if((num1 = write(fd2,s, strlen(s))) == -1) 
perror("write"); 
else 
printf("Write wrote %d bytes\n",num1); 
}while(flag == 0); 
return 0; 
} 
  
