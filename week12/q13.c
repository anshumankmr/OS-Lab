#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void copy(int arr1[], int arr2[], int num)
{
	int i;
   for (i = 0; i < num; i++) 
   {
      arr2[i] = arr1[i];
   }
}
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
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
void ScanDISK(int Array[], int header, int n,int lb, int ub)
{
	// printf("in here\n");
	printf("%d ->",header);
	int temp=n;
	int j=0;
	long mvmt=0;
	int pos[n];
	for (int i=0;i<n;i++)
	{
		pos[i]=i;
	}
	int array[n];
	copy(Array,array,n);
	bubbleSort(array,pos,n);
	while(temp>0)
	{
		for (int i= header; i<ub;i++)
		{
			if (array[j]==i)
			{
				printf("%d->",array[j]);
				mvmt+=abs(array[j]-header);
				header = array[j];
				array[j]=-1;
				pos[j]=-1;
				j+=1;
				temp--;
			}
			if (i==499)
			{
				mvmt+=abs(array[j]-getMax(array,n));
                break;
			}
		}
		for (int i = ub; i>lb;i++)
		{
			if (array[j]==i)
			{
				printf("%d->",array[j]);
				mvmt+=abs(array[j]-header);
				header = array[j];
				array[j]=-1;
				pos[j]=-1;
				j+=1;
				temp--;
			}
			if (i==0)
			{
				mvmt+=abs(array[j]-getMin(array,n));
                break;
			}
		}

	}
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
	printf("Enter the range of cylinders \n");
	int lb,ub;
	scanf("%d ",&lb);
	scanf("%d",&ub);
	printf("Header %d ",header);
	///int header1=header;
	ScanDISK(array,header,n,0,499);
}