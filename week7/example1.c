#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
int main(int arc, char ** argv)
{
	int n;
	int fd[2];
	char buf[1025];
	char* data="NIBBA";
	pipe(fd);
	write(fd[1],data,strlen(data));
	if ((n=read(fd[0],buf,1024))>=0)
	{
		buf[n]=0;
		printf("Read %d bytes from the pipe: \"%s\"\n",n,buf);
	}
	else
	{
		perror("Read");
	}
	exit(0);
}1