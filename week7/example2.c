#include <sys/wait.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char* argv[])
{
	int pfd[2];
	pid_t cpid;
	char buf[]="NIBBA";
	assert(argc==2);
	if (pipe(pfd)==-1)
	{
		perror("Pipe");
		exit(EXIT_FAILURE);
	}
	cpid=fork();
	if (cpid==-1)
	{
		perror("Fork");
		exit(EXIT_FAILURE);
	}
	if (cpid==0)
	{
     close(pfd[1]);
     while(read(pfd[0],&buf,1)>0)
     {
     	write(STDOUT_FILENO,buf,strlen(buf));
     	write(STDOUT_FILENO,"\n",1);
     	close(pfd[0]);
     	exit(EXIT_SUCCESS);
     }
    }
    else
    {
     close(pfd[1]);
     // while(read(pfd[0],&buf,1)>0)
     // {
     	write(pfd[1],argv[1],strlen(argv[1]));
     	close(pfd[1]);
        wait(NULL);
     exit(EXIT_SUCCESS);
     //}
    }
	

}