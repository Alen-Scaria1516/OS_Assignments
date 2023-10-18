#include<stdio.h> 
#include<stdlib.h> 
#include<errno.h> 
#include<string.h> 
#include<fcntl.h> 
#include<sys/types.h> 
#include<sys/stat.h> 
#include<unistd.h> 
#define FIFO_NAME "myfile.txt" 
 
int main(void) 
{ 
char s[300]; 
int num,fd;  
mkfifo(FIFO_NAME, 0666); 
printf("waiting for readers...\n"); // reader program 
fd = open(FIFO_NAME, O_WRONLY); // will open the writing end 
only --O_WRONLY 
printf("got a reader--type some stuff\n");int flag = 0; 
do 
{ int num; char s[300];  
gets(s); // the typed stuff will be stored in char s 
 
if((num = write(fd,s, strlen(s))) == -1) 
perror("write"); 
else 
printf("Writer wrote %d bytes\n",num);// if no error exists it will print 
the input  
if(s == 'exit') // if the input will be exit it will break and chat will end 
flag = 1; 
} while(flag != 1); // do while loop for continuous communication 
return 0; 
}

/*part 2*/
#include<stdio.h> 
#include<stdlib.h> 
#include<errno.h> 
#include<string.h> 
#include<fcntl.h> 
#include<sys/types.h> 
#include<sys/stat.h> 
#include<unistd.h> 
#define FIFO_NAME "myfile.txt" 
int main(void) 
{ 
char s[300]; 
int num,fd; 
mkfifo(FIFO_NAME, 0666); 
printf("waiting for writers...\n"); 
fd = open(FIFO_NAME, O_RDONLY); // open the read end  
printf("got a writer\n");int flag = 0; 
do 
{ 
char s[300]; int num;  
 
if((num = read(fd,s,300)) == -1) 
perror("read"); 
else{ 
s[num]= '\0'; 
printf("Reader read %d bytes\n",num);} 
if(s == 'exit') 
flag = 1; 
}while(flag == 0); 
return 0; 
}
