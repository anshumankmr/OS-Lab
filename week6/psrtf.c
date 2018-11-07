#include <stdio.h>
#include <limits.h>
void psjf()
{
	int n;
	printf("Enter the number of processes \n");
	scanf("%d",&n);
	int arrival[n+1],burst[n+1],temp[n+1],count =0;
	double  wait_time =0.0,turnaround_time = 0.0 , end_time = 0.0;
	for (int i = 0 ; i< n; i++)
	{
     printf("Enter the Arrival Time and Burst Time for Process %d \n", i +1 );
     scanf("%d",&arrival[i]);
     scanf("%d",&burst[i]);
     temp[i]=burst[i];
	}
	burst[n]= INT_MAX;
	for (int time  = 0; count != n; time++ )
	{
     int smallest = n;
     for (int j = 0; j<n;j++)
     {
     	if (arrival[j]<=time && burst[j]<burst[smallest] && burst[j] > 0)
     	{
     		smallest = j;
     	}
     }
     burst[smallest]-=1;
     if (burst[smallest]==0)
     {
     	count++;
     	end_time=time+1;
     	wait_time = wait_time +end_time -arrival[smallest]-temp[smallest];
     	turnaround_time= turnaround_time + end_time -arrival[smallest];
     	printf("Process %d has finished execution with turnaround time of %f and waiting time of %f \n",smallest+1,end_time-arrival[smallest], end_time -arrival[smallest]-temp[smallest]);
     }
     printf("Average Waiting Time of %f  \n",wait_time/n);
     printf("Average Turnaround Time of %f \n",turnaround_time/n );
	}
}
int main()
{
 psjf();
}