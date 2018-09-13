#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
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
		printf("This is the Child of Code 2\n");
		//char args[]={"q1"};
		execl("/home/student/Documents/anshuman/week_4/q1","./q1",(char*)NULL);
		printf("Execl Error\n");
	}
	else
	{   
		wait(NULL);
		printf("This is the Parent of Code 2\n");
	}
}