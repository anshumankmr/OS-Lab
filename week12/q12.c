#include <stdio.h>
#include <stdlib.h>
#include "q1.h"
void ScanDisk(int Array[], int header, int n , int lb, int ub)
{
  int array[n],pos[n];
  copy(Array,array,n);
  bubbleSort(array,pos,n);
  int header_locn,temp=n;
  for (int  i =0 ;i < n;i++)
  {
   if (array[i]==header)
    {
     header_locn =i;
     break;
    }
  }
 long mvmt =0;
 printf("SCAN Movement, assuming we move from right to left initially\n");
 for (int  i =header_locn;i>=0;i--)
  { 
   printf("%d->",array[i]);
   mvmt+= abs(array[i]-header);
   header=array[i];
   temp--;
  }
 if (temp!=0)
 {
   printf("%d->",lb);
   mvmt+=abs(lb-header);
   header=lb;
   for (int  i = header_locn+1;i<n;i++)
   {
    printf("%d->",array[i]);
    mvmt+= abs(array[i]-header);
    header=array[i];
    temp--;
   }
   if (temp!=0)
   { 
    printf("%d->",ub);
    mvmt+=abs(ub-header);
   }
 }
 printf("\nTotal movement %ld \n",mvmt);
}
void CScanDisk(int Array[], int header, int n , int lb, int ub)
{
  int array[n],pos[n];
  copy(Array,array,n);
  bubbleSort(array,pos,n);
  int header_locn,temp=n;
  for (int  i =0 ;i < n;i++)
  {
   if (array[i]==header)
    {
     header_locn =i;//is index not the location
     break;
    }
  }
 printf("C-SCAN Movement, assuming we move from left to right initially\n");
 long mvmt =0;
 for (int  i = header_locn;i<n;i++)
 {
   printf("%d->",array[i]);
   mvmt+= abs(array[i]-header);
   header=array[i];
   temp--;
 }
 if (temp!=0)
 {
  printf("%d->",ub);
  mvmt+=abs(ub-header);
  printf("%d->",lb );
  header=lb;
  for (int  i =0 ;i<header_locn;i++)
  { 
   printf("%d->",array[i]);
   mvmt+= abs(array[i]-header);
   header=array[i];
   temp--;
  }
 } 
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
  CScanDisk(array,header,n,lb,ub);
}
