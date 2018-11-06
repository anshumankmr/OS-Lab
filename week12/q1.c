#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int flag=0;
void copy(int arr1[], int arr2[], int num)
{
	int i;
   for (i = 0; i < num; i++) 
   {
      arr2[i] = arr1[i];
   }
}
int getMax(int arr[], int n)
{
	int max=arr[0];
	for (int i=1;i<n;i++)
	{
		if (arr[i]>max)
		{
			max=arr[i];
		}
	}
	return max;
}
int getMin(int arr[], int n)
{
	int min=-10;
	for (int i=0;i<n;i++)
	{
		if (arr[i]==-1)
		{
			continue;
		}
		if (arr[i]<min)
		{
			min=arr[i];
		}
	}
	return min;
}
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
int usecase(int diff[], int n)//to deal with varying cases of difference values
{
	int zc=-1,i;
	for (  i =0 ;i < n ; i++)
	{
		if (diff[i]!=0 && zc == -1) // in case no value of the difference is zero
		{
			return i;
		}
		if (zc==-1 && diff[i]==0)
		{
         zc+=1;
		}
		if (zc > -1 && diff[i]==0 && flag > 0 && i!=0 )// to deal with use case where there are multiple places with same value
		{
			flag+=1;
			return flag;
		}
		if (zc>-1 && diff[i]!=0)
		{
			return i;
		}
	}
}
int getShortest(int array[], int header, int n)
{
	int diff[n], pos[n];
	for (int i=0;i<n;i++)
	{
		pos[i]=i;
	// }
	// for (int i =0 ;i<n; i++)
	// {
		diff[i]=abs(array[i]-header);
		//printf("\n diff %d %d ",i , diff[i] );
	}
	bubbleSort(diff,pos,n);
    return pos[usecase(diff,n)];
    
}
void srtf(int Array[], int header, int n)
{
	printf("%d->",header );
	long mvmt=0;
	int array[n];
	copy(Array,array,n);
	for (int i =0; i<n;i++)
    {
	 int pos = getShortest(array,header,n);
     printf("%d->",array[pos] );
     mvmt+=abs(array[pos]-header);
     header=array[pos];
     array[pos]=INT_MAX;
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
    printf("FCFS Ordering\n");
	fcfs(array,header,n);
	printf("SSTF Ordering\n");
	srtf(array,header,n);
}