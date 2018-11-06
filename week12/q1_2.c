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
void ScanDisk(int array[], int header, int n , int lb, int ub)
{
  bubbleSort(array,n);
  int header_locn;
  for (int  i =0 ;i < n;i++)
  {
   if (array[i]==header)
    {
     header_locn =i;
     break;
    }
  }
 long mvmt =0;
 for (int  i =header_locn;i>=0;i--)
  { 
   printf("%d->",array[i]);
   mvmt= abs(array[i]-header);
   header=array[i];
  }
 printf("%d->",lb);
 mvmt=abs(lb-header);
 for (int  i = header_locn;i<n;i++)
 {
   printf("%d->",array[i]);
   mvmt= abs(array[i]-header);
   header=array[i];
 }
 printf("%d->",ub);
 mvmt=abs(ub-header);
 printf("\nTotal movement %ld \n",mvmt);
}
int main()
{
	printf("Enter the range of cylinders \n");
	int lb,ub;
	scanf("%d ",&lb);
	scanf("%d",&ub);
	int array[200], n ,header;
	printf("Enter the header\n");
    scanf("%d",&header);
	printf("Enter the total number of requests\n");
	scanf("%d",&n);
	printf("Enter the array of requests\n");
	for (int i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	array[n]=header;
	n+=1;
	ScanDisk(array,header,n,lb,ub);
}
