#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <pthread.h>
struct Array 
{
	int arr[1000];
	int length;
	int evensum,oddsum;
};
void* evensum(void* param)
{
	
	struct Array* obj = (struct Array*)param;
	int evensum=0;
	for (int i=0;i<obj->length;i++)
	{
		if (obj->arr[i]%2==0)
		{
			 evensum+=obj->arr[i];
		}
	}
	obj->evensum=evensum;
	//printf("\nFunction Even Sum %d\n",obj->evensum );
	return (void*)obj->evensum;
}
void* oddsum(void* param)
{
	struct Array* obj = (struct Array*)param;
	int oddsum=0;
	//printf("Hei\n");
	for (int i=0;i<obj->length;i++)
	{
		if (obj->arr[i]%2!=0)
		{
			//printf(" saa %d\n",obj->arr[i] );
			oddsum+=obj->arr[i];
		}
	}
	obj->oddsum=oddsum;
	//printf("\nFunction Odd Sum %d\n",obj->oddsum );
	return (void*)obj->oddsum;
}
int main()
{
	struct Array* obj=malloc(sizeof(struct Array));
	printf("Enter a length for the array \n");
    scanf("%d",&obj->length);
    printf("Enter the elements \n");
    for (int i=0;i<obj->length;i++)
    {
    	scanf("%d",&obj->arr[i]);
    }
    pthread_t thread_even,thread_odd;
    printf("\nThread made\n");
    void  *even,*odd=NULL;
    pthread_create(&thread_even,0,&evensum,(void*)obj); 
    pthread_join(&thread_even,&even);
    wait(500);
    pthread_create(&thread_odd,0,&oddsum,(void*)obj);
    pthread_join(&thread_odd,&odd);   
    printf("\n");
  
    printf("\nEven Sum %i ",(intptr_t)even);
    printf("\nOdd Sum %i ",(intptr_t)odd);
}