#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
  
        // If no two elements were swapped by inner loop,
        // then break
        if (swapped == false)
            break;
    }
}

int main(void)
{
	int n,fd[2];
	printf("Enter the length of the array: ");
	scanf("%d",&n);
	pid_t pid;
	int arr[n];
	int arr1[n];
	printf("Enter the array of integers:\n");
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	if(pipe(fd)==-1) exit(1);
	else printf("PIPE created by parent successfully\n");
	if((pid=fork())<0) exit(1);
	else if(pid>0){
		close(fd[0]);
		for(int i= 0;i<n;i++)
		{
			write(fd[1],&arr[i],sizeof(int));
		}
		//write(fd[1],&x,sizeof(int)); for writing an int to the file
	}
	else 
	{
		close(fd[1]);
		for(int i = 0;i<n;i++)
		{
			int len = read(fd[0],&arr1[i],sizeof(int));
		} 
		printf("The received array is :\n");	
		for(int i = 0;i<n;i++)
		{
			printf("%d ",arr1[i]);
		}
		printf("\n");
		bubbleSort(arr1,n);
		printf("The sorted array is :\n");
		for(int i = 0;i<n;i++)
		{
			printf("%d ",arr1[i]);
		}
		printf("\n");
	}	
	return 0;
}
