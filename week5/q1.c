#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct fibonacci
{
	int arr[100];
	int num;
}fibo ;
void* fibo_series(void* param)
{
 fibo* fib = (fibo *)param;
 fib->arr[0]=0;
 fib->arr[1]=1;
 printf("The number of terms are %d\n",fib->num);
 if (fib->num<=2 )
 {
 	return (void*)fib->arr;
 }
 else
 {
  for (int i =2;i<fib->num;i++)
  {
  	fib->arr[i]=fib->arr[i-1]+fib->arr[i-2];
  	//printf("%d \n",fib->arr[i]);
  }
  return (void*)fib->arr;
 }
}
int main()
{
	pthread_t thread;
	fibo * fib = (fibo *)malloc(sizeof(fibo));
	//fibo fib;
	printf("Enter the number of terms\n");
	scanf("%d",&(fib->num));
    int array[fib->num];
    pthread_create(&thread,0,&fibo_series,(void*)fib);
    pthread_join(thread,(void**)array);
    for (int i=0;i<fib->num;i++)
    {
    	printf("%d ",fib->arr[i]);
    }

}