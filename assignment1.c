#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h> 

int main()
{
	int i;
	int n;
	printf("Enter the number of childs processes(N): ");
	scanf("%d",&n);
	//On successful forking 
	/*if(p>0){
		waitpid(p,0,0);
		printf("\nI am Parent of PID %d\n",p);
		sleep(n-1);
		exit(0);
		
	}*/
	for(int i=1;i<=n;i++)
	{	
		int child_pid = fork();
		//Error while forking
		if(child_pid>0){
			waitpid(child_pid,0,0);
			printf("\nI am Parent of PID %d\n",child_pid);
			sleep(n-1);
			exit(0);
			
		}
		if(child_pid==-1)
		{
			perror("fork"); 
			exit(1);
		}
		else if(child_pid==0)//child process
		{
			printf("Child No: %d, Child_PID: %d, Parent_PID: %d.\n",i,getpid(),getppid());
			exit(0);
		}
	}
	return 0;
		
}
