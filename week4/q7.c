#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
int main()
{
	char dirname[10];
	DIR* p;
	struct dirent *d;
	printf("Enter a directory name:\n");
	scanf("%s",dirname);
	p=opendir(dirname);
	if (p== NULL)
	{
		printf("Cannot Find the Directory \n");
		exit(0);
	}
	while (d= readdir(p))
	{
	 printf("%s\n",d->d_name );
	}
	return 0;
}