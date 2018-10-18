#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#define TEXT_SZ 2048
struct shared_use_st{
	int written_by_you;
	char text[TEXT_SZ];
};

int main(){
	int running = 1;
	void *shared_memory = (void *)0;
	struct shared_use_st *shared_stuff;
	int shmid;
	shmid = shmget((key_t)1235,sizeof(struct shared_use_st),0666|IPC_CREAT);
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
	while(running){
		if(shared_stuff->written_by_you){
			printf("You wrote : %s\n",shared_stuff->text);
			sleep(rand()%4);
			shared_stuff->written_by_you = 0;
			if(strncmp(shared_stuff->text,"end",3)==0){
				running = 0;
			}
		}
	}
	if(shmdt(shared_memory)==-1){
		fprintf(stderr, "shmdt failed\n");
		exit(1);
	}
	if(shmctl(shmid,IPC_RMID,0)==-1){
		fprintf(stderr, "shmctl(IPC_RMID) failed\n");
		exit(1);
	}
	exit(0);
}

