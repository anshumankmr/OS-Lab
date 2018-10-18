#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
struct my_msg_st
{
	long int my_msg_type;
	int number;
};
int Palindrome(int n)
{
	int reverse=0,temp=n;
	while(temp>0)
	{
		reverse=reverse*10 + temp%10;
		temp/=10;
	}
	if (n==reverse)
	{
		return 1;
	}
	return 0;
}
int main()
{
	int running=1;
	int msgid;
	struct my_msg_st some_data;
	long int msg_to_receive=0;
	msgid=msgget((key_t)1234,0666|IPC_CREAT);
	if (msgid==-1)
	{
		fprintf(stderr, "msgget failed with the error: %d\n",errno );
		exit(EXIT_FAILURE);
	}
	while (running)
	{
		if (msgrcv(msgid,(void*)&some_data,BUFSIZ,msg_to_receive,0)==-1)
		{
         fprintf(stderr, "msgrcv failed with error %d\n", errno);
         exit(EXIT_FAILURE);
   		}
   		
   		if(some_data.number==-1)
   		{
   			running=0;
   		}
   		else
   		{
   			printf("You Wrote: %d \n",some_data.number);
         if (Palindrome(some_data.number ))
         {
         	printf("This is a Palindrome \n");
         }
         else
         {
         	printf("This is not a Palindrome \n");
         }
   		}
	}
    if (msgctl(msgid,IPC_RMID,0)==-1)
    {
    	fprintf(stderr, "msgctl(IPC_RMID) failed\n");
    	exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}