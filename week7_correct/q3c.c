#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
struct shared_use_st{
	int written_by_you;
	char c;
};

int main(){
	void *shared_memory = (void *)0;
	struct shared_use_st *shared_stuff;
	int shmid;
	shmid = shmget((key_t)1234,sizeof(struct shared_use_st),0666|IPC_CREAT);
	if(shmid==-1){
		fprintf(stderr, "shmget failed\n");
		exit(1);
	}
	shared_memory = shmat(shmid,(void *)0,0);
	if(shared_memory == (void *)-1){
		fprintf(stderr, "shmmat failed\n");
		exit(1);
	}
	shared_stuff = (struct shared_use_st *)shared_memory;
	shared_stuff->written_by_you = 0;

	int pid = fork();

	if(pid == 0){
		while(1){
			if(shared_stuff->written_by_you){
				if(shared_stuff->c == 'z') shared_stuff->c = 'a';
				else if(shared_stuff->c == 'Z') shared_stuff->c = 'A';
				else shared_stuff->c++;
				exit(0);
			}
		}
	}else{
		printf("Enter character :\n");
		char c;
		scanf("%c",&c);
		shared_stuff->c = c;
		shared_stuff->written_by_you = 1;
		wait(NULL);
		printf("Next character : %c\n",shared_stuff->c);
	}
}

