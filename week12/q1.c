#include <stdio.h>
#include <stdlib.h>
void fcfs(int array[], int header, int n)
{
	printf("%d->",header );
	long mvmt=0;
	for (int i =0; i<n;i++)
	{
     printf("%d->",array[i] );
     mvmt+=abs(array[i]-header);
     header=array[i];
	}
	printf("\nTotal movement of header %ld\n",mvmt );
}
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
void bubbleSort(int arr[],int pos[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
    {   
       for (j = 0; j < n-i-1; j++)
       {  
           if (arr[j] > arr[j+1]) 
           	 {
              swap(&arr[j], &arr[j+1]);
              swap(&pos[j], &pos[j+1]); 
           	 }
        }
     }      	 
} 

int getShortest(int array[], int header, int n)
{
	int diff[n], pos[n];
	for (int i=0;i<n;i++)
	{
		pos[i]=i;
	}
	for (int i =0 ;i<n; i++)
	{
		diff[i]=abs(array[i]-header);
		//printf("\n diff %d %d ",i , diff[i] );
	}
	bubbleSort(diff,pos,n);
	printf("|%d - %d| = %d \n",pos[0],header, diff[0]);
	return pos[0];
}
void srtf(int array[], int header, int n)
{
	printf("%d->",header );
	long mvmt=0;
	for (int i =0; i<n;i++)
	{
	 int pos = getShortest(array,header,n);
     printf("%d->",array[pos] );
     mvmt+=abs(array[pos]-header);
     header=array[pos];
	}
	printf("\nTotal movement of header %ld\n",mvmt );
}
int main()
{
	int array[200], n ,header;
	printf("Enter the total number of requests\n");
	scanf("%d",&n);
	printf("Enter the array of requests\n");
	for (int i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
    printf("Enter the header\n");
    scanf("%d",&header);
	fcfs(array,header,n);
	srtf(array,header,n);
}