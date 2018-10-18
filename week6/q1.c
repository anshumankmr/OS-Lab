#include <stdio.h>
#include <stdlib.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)      
    {
      	for (j = 0; j < n-i-1; j++)
       {
           if (arr[j] > arr[j+1])
            { 
             swap(&arr[j], &arr[j+1]);
            }
       }
    } 
}
void fcfs(int arr[],int time[],int priority[],int n)
{
 bubbleSort(arr);
}
int main()
{
	int arr[100],time[100],priority[100],n;
	printf("Enter the number of processes\n");
	scanf("%d",&n);
	for (int i =0 ;i < n;i++)
	{
		printf("Burst time for process P%d ",i);
		scanf("%d",&time[i]);
		printf("Arrival Time time for process P%d ",i);
		scanf("%d",&arr[i]);
		printf("Priority for process P%d ",i);
        scanf("%d",&priority[i]);
	}
	fcfs(arr,time,priority,n);
}