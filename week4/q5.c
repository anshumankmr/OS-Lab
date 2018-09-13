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
	my_file=creat("code.txt",0777);
    char str[80];
    printf("Write:\n");
    scanf("%s",str);
    //printf(str);
    //int length= strlen(string);
    write(my_file,str,strlen(str));
    close(my_file);
}
