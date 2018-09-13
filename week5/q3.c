#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <pthread.h>
int isPrime(int n)
{
	if (n==1)
	{
		return 0;
	}
	else if (n == 2 || n == 3 )
	{
		return 1;
	}
	else
	{
		int ret=1;
		for (int i=2;i<=sqrt(n);i++)
		{
			if (n%i==0)
			{
				ret=0;
				break;
			}
		}
		return ret;
	}
}
typedef struct Prime
{
	int arr[1000];
	int lb,ub;
}prime;
void* primeRange (void* param)
{
	prime* obj = (prime* )param;
	int j=0;
	for (int i = obj->lb; i <= obj->ub; i++)
	{
		if(isPrime(i))
		{
			obj->arr[j++]=i;
		}
	}
	return (void*)j;
}
int main()
{
 pthread_t thread;
 prime* obj = (prime*)malloc(sizeof(prime));
 printf("Enter the lower and the upper bound \n");
 scanf("%d %d",&obj->lb,&obj->ub);
 int  len;
 pthread_create(&thread,0,&primeRange,(void*)obj);
 pthread_join(thread,(void**)&len);
 printf("The prime numbers between %d and %d are ",obj->lb,obj->ub);
 for (int i = 0  ; i < len ;i++)
 {
 	printf("%d " ,obj->arr[i]);
 }
 printf("\n");
}