#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
	pid_t pid;
	pid=fork();
	if (pid<0)
	{
		printf("Forking failed\n");
	}
	else if (pid==0)
	{
		printf("This is the Process ID of the Child %d\n",getpid());
		printf("This is the Process ID of the Child's Parent %d\n",getppid());
	}
	else
	{   
		wait(NULL);
		printf("This is the Process ID of the Parent %d\n",getpid());
		printf("This is the Process ID of the Parent's Child %d\n",pid);	
	}
}
