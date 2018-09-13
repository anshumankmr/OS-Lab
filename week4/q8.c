#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
int main()
{
	int my_file;
	my_file=open("sample.txt",O_RDWR);
    char string[10000];
    int ch_count=0,word_count=0,line_count=1,i=0;
    read(my_file,string,sizeof(string));
    //ch=string[0];
    while(string[i]!='\0')
    {   
    	if (string[i]!=' ')
    	{
    		ch_count++;
    	}
    	else if (string[i]==' ' && string[i+1]!=' ')
    	{
          word_count++;
    	}
      if (ch_count%80==0)
    	{
    		line_count++;
    	}
    	i++;
    }
    printf("Word Count %d \n",word_count);
    printf("Line Count %d \n",line_count);
    printf("Character Count %d \n",ch_count);
    close(my_file);
}
