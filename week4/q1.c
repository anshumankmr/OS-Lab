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
		printf("This is the Child\n");
	}
	else
	{   
		wait(NULL);
		printf("This is the Parent\n");
	}
}