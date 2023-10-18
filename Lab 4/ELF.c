/*part 1*/
#include<stdio.h> 
#include<unistd.h> 
#include<stdlib.h> 
int main(int argc, char *argv[]) 
{ 
  printf("PID of file1.c = %d\n", getpid()); 
  char *args[]={"Hello","World",NULL}; 
  execv("./file2", args); // executable file of 2nd program will be 
exectuded through this file 
  printf("Back to file1.c"); 
  return 0; 
}   

/*part 2 */
#include<stdio.h> 
#include<unistd.h> 
#include<stdlib.h> 
int main(int argc , char *argv[]) 
{ 
   printf("we are in file2.c\n"); 
   printf("PID of file2.c = %d\n" , getpid()); 
   return 0; }   
