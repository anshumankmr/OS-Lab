#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

sem_t wrt, mutex;
int readcount = 0;

void *writer(void *arg)
{
    sem_wait(&wrt);
    printf("WWW - Writer %d is operating\n\n", (int)arg);
    printf("WWW - Writer %d done\n\n",(int)arg);
    sem_post(&wrt);
}

void *reader(void *arg){
    
    sem_wait(&mutex);
    readcount++;
    if(readcount == 1)
        sem_wait(&wrt);
    sem_post(&mutex);
    printf("RRR - Reader %d is operating\n\n",(int)arg);
    sem_wait(&mutex);
    readcount--;
    if (readcount == 0)
        sem_post(&wrt);
    printf("RRR - Reader %d done\n\n", (int)arg);
    sem_post(&mutex);
}

void main(){

    int i = 1, j = 1;
    pthread_t r1,r2,r3,w1,w2;
    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);
 
    pthread_create(&r1, NULL, reader, (void *)i++);
   pthread_create(&w1, NULL, writer, (void *)j++);
    pthread_create(&r2, NULL, reader, (void *)i++);
    pthread_create(&w2, NULL, writer, (void *)j++);
    pthread_create(&r3, NULL, reader, (void *)i++);

   
    pthread_join(r1, NULL);
 pthread_join(w1, NULL);
    pthread_join(r2, NULL);
    pthread_join(w2, NULL);
    pthread_join(r3, NULL);
}


