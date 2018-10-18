#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h> 
#include <sys/msg.h> 

struct msg_buffer {
	long int msg_type;
	int num;
} msg;

int main() {
	int msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
	msg.msg_type = 1;

	int n;
	printf("Enter\n");
	scanf("%d", &msg.num);

	msgsnd(msgid, &msg, sizeof(msg), 0);
}


