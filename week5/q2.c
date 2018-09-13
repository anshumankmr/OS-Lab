#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct Sum
{
	int sum;
	int num;
}sumstruct ;
void* sum(void* param)
{
 sumstruct* fib = (sumstruct *)param;
 //fib->arr[0]=0;
 fib->sum=0;
 //printf("The number of terms are %d\n",fib->num);
 for (int i = 1 ;i<=fib->num;i++)
  {
  	fib->sum+=i;
  }
  return (void*)fib->sum;

}
int main()
{
	pthread_t thread;
	sumstruct * fib = (sumstruct *)malloc(sizeof(sumstruct));
	//sumstruct fib;
	printf("Enter the number of terms\n");
	scanf("%d",&(fib->num));
  int array;
  pthread_create(&thread,0,&sum,(void*)fib);
  pthread_join(thread,(void**)array);
  printf("%d ",fib->sum);
}