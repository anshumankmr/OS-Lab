#include<stdio.h>
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
int main()
{
 int i,n,p[10]={1,2,3,4,5,6,7,8,9,10},min,k=1,btime=0;
 int bt[10],temp,j,at[10],wt[10],tt[10],ta=0,sum=0;
 float wavg=0,tavg=0,tsum=0,wsum=0;
 printf(" -------Shortest Job First Scheduling ( NP )-------\n"); 
 printf("\nEnter the No. of processes :");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
 printf("\tEnter the burst time of %d process :",i+1);
 scanf(" %d",&bt[i]);
 printf("\tEnter the arrival time of %d process :",i+1);
 scanf(" %d",&at[i]);
 }
 
for(i=0;i<n;i++)
{
 for(j=0;j<n;j++)
 {
  if(at[i]<at[j])
  {
   swap(&p[i],&p[j]);
   swap(&at[i],&at[j]);
   swap(&bt[i],&bt[j]);
  }
 }
}
 
/*Arranging the table according to Burst time,
Execution time and Arrival Time
Arrival time <= Execution time
*/
 
 for(i=0;i<n;i++)
 {
  btime=btime+bt[i];
  min=bt[k];
  for(j=k;j<n;j++)
  {
   if (btime>=at[j] && bt[j]<min)
   {
    swap(&p[k],&p[j]);
    swap(&a[k],&a[j]);
    swap(&b[k],&b[j]);
   }
  }
   k++;
 }
 wt[0]=0;
 for(i=1;i<n;i++)
 {
  sum=sum+bt[i-1];
  wt[i]=sum-at[i];
  wsum=wsum+wt[i];
 }
 wavg=(wsum/n);
 for(i=0;i<n;i++)
 {
  ta=ta+bt[i];
  tt[i]=ta-at[i];
  tsum=tsum+tt[i];
  }
 tavg=(tsum/n);
 printf("************************");
 printf("\n RESULT:-");
 printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around" );
 for(i=0;i<n;i++)
 {
  printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d",p[i],bt[i],at[i],wt[i],tt[i]);
 }
printf("\n\nAVERAGE WAITING TIME : %f",wavg);
printf("\nAVERAGE TURN AROUND TIME : %f",tavg);
return 0;
}