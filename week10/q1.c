#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 
void copy (int arr[],int arr1[],int n)
{
 for (int i=0;i<n;i++)
 {
 	arr1[i]=arr[i];
 }
}
void bestfit(int proc[],int Part[], int n, int p)
{
	int dif,minpos;
	int part[n];
	copy(Part,part,n);
	for (int i =0 ;i<p;i++)
	{
		dif=INT_MAX;
		minpos=-1;
		for (int j=0;j<n;j++)
		{
          if (part[j]-proc[i]<dif && part[j]-proc[i]>=0  )
          {
          	dif=part[j]-proc[i];
          	minpos=j;
          }
		}
		if (minpos == -1 && dif == INT_MAX)
		{
			printf("No partitions big enough for process %d with size %d\n",i+1,proc[i]);
		}
		else
		{
			printf("The Process P%d fits in location %d leaving space %d in it\n",i+1,minpos+1,dif);
			part[minpos]-=proc[i];
		}
	}
}
void firstfit(int proc[],int Part[], int n, int p)
{
	int part[n];
	int dif;
	copy(Part,part,n);
	for (int i =0 ;i<p;i++)
	{
		int pos=-1;
		for (int j=0;j<n;j++)
		{
          if (part[j]-proc[i]>=0  )
          {
          	pos=j;
          	break;
          }
		}
		if (pos == -1)
		{
			printf("No partitions big enough for process %d with size %d\n",i+1,proc[i]);
		}
		else
		{
			printf("The Process P%d fits in location %d leaving space %d in it\n",i+1,pos+1,part[pos]-proc[i]);
			part[pos]-=proc[i];
		}
	}
}
void worstfit(int proc[],int Part[], int n, int p)
{
	int part[n];
	int dif;
	copy(Part,part,n);
	bubbleSort(part,n);
	for (int i =0 ;i<p;i++)
	{
		int pos=0;
		for (int j=n-1;j>=0;j--)
		{
          if (part[j]-proc[i]>=0  )
          {
          	pos=j;
          	break;
          }
		}
		if (pos == 0)
		{
			printf("No partitions big enough for process %d with size %d\n",i+1,proc[i]);
		}
		else
		{
			printf("The Process P%d fits in location %d leaving space %d in it\n",i+1,pos+1,part[pos]-proc[i]);
			part[pos]-=proc[i];
		}
	}
}
int main()
{
	printf("Enter the number of partitions\n");
	int n;scanf("%d",&n);
	int part[n];
	printf("Enter the number of processes\n");
	int p;scanf("%d",&p);
	int proc[p];
	printf("Enter the size of each partition\n");
	for (int i=0;i<n;i++)
	{
		scanf("%d",&part[i]);
	}
	printf("Enter the size of each process\n");
	for (int i=0;i<p;i++)
	{
		scanf("%d",&proc[i]);
	}
	printf("Best Fit\n");
	bestfit(proc,part,n,p);
	printf("\nFirst Fit \n");
	firstfit(proc,part,n,p);
	printf("\nWorst Fit \n");
	worstfit(proc,part,n,p);
}