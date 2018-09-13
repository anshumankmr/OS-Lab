#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
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
		printf("This is the Child\n");
		printf("\n%d\n",getpid());
		wait(NULL);
	}
	else
	{   
		//wait(NULL);
		printf("This is the Parent\n");
		printf("\n%d\n",getpid());
		exit(0);
	}
	printf("\n%d\n",getpid());
}