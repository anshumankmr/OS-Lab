#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[], int time[],int priority[],int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)      
    {
      	for (j = 0; j < n-i-1; j++)
       {
           if (arr[j] > arr[j+1])
            { 
             swap(&arr[j], &arr[j+1]);
             swap(&time[j],&time[j+1]);
             swap(&priority[j],&priority[j+1]);
            }
       }
    } 
}
void roundrobin(int arr[],int time[],int priority[],int n)
{
 bubbleSort(arr,time,priority,n);//sort all inputs
 int wait[n];//={ };
 int tottime=0;//total time spent in execution ie not idle.
 int turn[n];
 memset( wait, 0, n*sizeof(int) );
 memset( turn,0, n*sizeof(int) );
 for (int i = 0;i<n;i++)
 {
  printf("Process with priority %d is executing\n",priority[i]);
  
 }
 float avgwait=0.0,avgburst=0.0;
 for (int i=0;i<n;i++)
 {
 	avgburst+=turn[i];
 	avgwait+=wait[i];
  }
  avgwait/=n;avgburst/=n;
  printf("Average Burst Time %f ",avgburst);
  printf("\nAverage Wait Time %f \n",avgwait );
}
int main()
{
	int arr[100],time[100],priority[100],n;
	printf("Enter the number of processes\n");
	scanf("%d",&n);
	for (int i =0 ;i < n;i++)
	{

		printf("Arrival Time time for process P%d ",i);
		scanf("%d",&arr[i]);
		+
		printf("Burst time for process P%d ",i);
		scanf("%d",&time[i]);
		
		printf("Priority for process P%d ",i);
        scanf("%d",&priority[i]);
	}
	roundrobin(arr,time,priority,n);
}