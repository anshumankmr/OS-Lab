#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct array_struct
{
  int *arr;
  int num;
}evenodd ;
void* sum_even(void* param)
{
 evenodd* array = (evenodd *)param;
 int even=0;
 for (int i = 0; i< array->num;i++)
 {
  printf("%d ",array->arr[i]);
  if (array->arr[i]%2==0)
  {
   even+=array->arr[i];
   printf("Even %d\n",even);
  }
 } 
 return (void*)even;
}
void* sum_odd(void* param)
{
 evenodd* array = (evenodd *)param;
 int odd=0;
 for (int i = 0; i< array->num;i++)
 {
  printf("%d ",array->arr[i]);
  if (array->arr[i]%2!=0)
  {
   odd+=array->arr[i];
   printf("Odd %d\n",odd);
  }
 }
 return (void*)odd;
}
int main()
{
  pthread_t thread_even,thread_odd;
  evenodd * fib = (evenodd *)malloc(sizeof(evenodd));
  printf("Enter the number of terms\n");
  scanf("%d",&(fib->num));
  fib->arr=(int *)malloc(sizeof(int)*fib->num);
  //printf("%d ",fib->num);
  printf("\nEnter the terms\n");
  for (int i=0 ;i<fib->num;i++)
  {
   scanf("%d",&(fib->arr[i]));
   printf("%d ",fib->arr[i]);
  }
  printf("Helo\n");
  int sum_odd,sum_even;
  pthread_create(&thread_even,0,&sum_even,(void*)fib);
  pthread_create(&thread_odd,0,&sum_odd,(void*)fib);
  pthread_join(thread_even,(void**)&sum_even);
  pthread_join(thread_odd,(void**)&sum_odd);
  printf("\n The sum of the even elements are %i",sum_even);
  printf("\n The sum of the odd elements are %i",sum_odd);
}