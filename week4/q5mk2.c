#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	int my_file;
	my_file=open("code.txt",O_RDWR);
    char string[80];
    printf("Write:\n");
    scanf("%s",string);
    printf(string);
    //int length= strlen(string);
    printf("%d",write(my_file,string,strlen(string)));
    close(my_file);
}
