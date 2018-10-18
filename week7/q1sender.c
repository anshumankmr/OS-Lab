#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX_TEXT 512
struct my_msg_st
{
	long int my_msg_type;
	int number;
};
int main()
{
	int running=1;
	struct my_msg_st some_data;
	int msgid;
	char buffer[BUFSIZ];
	msgid=msgget((key_t)1234,0666|IPC_CREAT);
	if (msgid==-1)
	{
		fprintf(stderr, "msgget failed with error %d\n",errno);
	    exit(EXIT_FAILURE);
	}
	while(running)
	{
		printf("Enter some a number:");
		//fgets(buffer,BUFSIZ,stdin);
		scanf("%d",&some_data.number);
		some_data.my_msg_type=1;
		//strcpy(some_data.some_text,buffer);
		if (msgsnd(msgid,(void*)&some_data,MAX_TEXT,0)==-1)
		{
			fprintf(stderr, "msgsnd failed\n" );
			exit(EXIT_FAILURE);
		}
		if (some_data.number==-1)
		{
			running=0;
		}
	}
	exit(EXIT_SUCCESS);
}