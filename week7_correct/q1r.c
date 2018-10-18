#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h> 
#include <sys/msg.h> 

struct msg_buffer {
	long int msg_type;
	int num;
} msg;

void palin(int n) {
	int t = n;
	int r, s = 0;
	while(t!=0) {
		r = t%10;
		s = s*10 + r;
		t = t/10;
	}
	if(s == n)
		printf("%d is palindrome.\n", n);
	else
		printf("%d is not palindrome.\n", n);
}

int main() {
	int msgid = msgget((key_t)1234, 0666 | IPC_CREAT);

	msgrcv(msgid, &msg, sizeof(msg), 1, 0);

	printf("Number received : %d\n", msg.num);
	palin(msg.num);
}

