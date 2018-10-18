#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int timeisleft(int arr[],int n)
{
    printf("timeisleft\n");
  int ret=0;
  for (int i = 0; i<n; i++)
  {
    
    if (arr[i]>0)
    {
     ret=1;
     break;
    }
  }
  return ret;
}
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
int get_shortest_at_same_time(int arr[], int time[],int i , int n)
{
  int j;
    printf("get_shortest_at_same_time;;\n");
  int min_time=time[j], min_pos=0;
  for (j=0;j<n;j++)
  {
    if (j!=i)
    {
      continue;
    }
    if (min_time>time[j] && time[j]!=0)
    {
      min_time=time[j];
      min_pos=j;
    }
  }
  return min_pos;
}
int preempt(int arr[],int time[],int i, int n)
{
  int min_time=time[i],min_pos=i,j;
    printf("helll oqwrkl lf ;\n");
  for (j= i;j < n ;j++)
  {
   if (arr[j]>arr[min_pos] && time[j]<min_time)
   {
    min_time=time[j];
    min_pos=j;
   }
  }
  if (j==i)
  {
    return i;
  }
  return j;
}
void shortestremainingtimefirst(int arr[],int time[],int priority[],int n)
{
 bubbleSort(arr,time,priority,n);//sort all inputs
 int wait[n];//={ };
 int tottime=0;//total time spent in execution ie not idle.
 int turn[n];
 memset( wait, 0, n*sizeof(int) );
 memset( turn,0, n*sizeof(int) );
 int i;
 do
 {
  i=0;
  printf("shortestremainingtimefirst;;\n");
  //printf("Process with priority %d is executing\n",priority[i]);
  if (!timeisleft(time,n))
  {
    break;
  }
  int j= get_shortest_at_same_time(arr,time,i,n);
//int j=process_id;
  printf("Process with priority %d is executing ",priority[j]);
  while(j<n)
  {
   int p=preempt(arr,time,j,n);
   if (p!=j)
   {
    time[j]-=arr[j];
    printf("Process with priority %d is executing ",priority[j]);
    break;
   }
   else if (p==j)
   {
    time[j]=0;
   }
  };
 }while(1);
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
		printf("Burst time for process P%d ",i);
		scanf("%d",&time[i]);
		printf("Priority for process P%d ",i);
    scanf("%d",&priority[i]);
	}
	shortestremainingtimefirst(arr,time,priority,n);
}