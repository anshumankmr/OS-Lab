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
              // swap(&pos[j], &pos[j+1]); 
             }
        }
     }          
} 
void ScanDisk(int Array[], int header, int n,int lb, int ub)
{
  printf("%d ->",header);
  int proc= n,array[n],j;
  long mvmt=0;
  copy(Array,array,n);
  bubbleSort(array,n);
      for (int  i =0 ; i < 499 ; i++)
    {
      j =0;
      while (j < n)
      {
         if (array[j]==i && array[j]!=INT_MAX && array[j]>header)
         {
          printf("%d -> \n",array[j]);
          mvmt += abs(array[j]-header);
          header = array[j];
          array[j]=INT_MAX;
          proc--;
         }
         
         j++;
      }
    }
    for (int  i =499;i>=0 ; i--)
    {
      j =0;
      while (j < n)
      {
         if (array[j]==i && array[j]!=INT_MAX && array[j]>header)
         {
          printf("%d -> \n",array[j]);
          mvmt += abs(array[j]-header);
          header = array[j];
          array[j]=INT_MAX;
          proc--;
         }
         j++;
      }
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
  printf("Assuming the range of cylinders is from 0 - 499 and we are moving from 0 to 499\n");
  // int lb,ub;
  // scanf("%d ",&lb);
  // scanf("%d",&ub);
  //printf("%d ",header);
  ScanDisk(array,header,n,0,499);

}