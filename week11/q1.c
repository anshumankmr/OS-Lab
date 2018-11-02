#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Modules independent of Algorithm
int j;
int positionsareempty(int arr[], int frame)
{
    int ret=0;
    for (int i =0;i<frame;i++)
    {
        if (arr[i]==-1)
        {
            ret=1;
            break;
        }
    }
    return ret;
}
void printdist(int arr[], int frame)
{
    printf("Frame Table\n");
    for (int i =0;i<frame;i++)
    {
        printf("%d ", arr[i]);
    }
}
//can use this for verification

int hit(int page, int arr[], int size)
{
    for (int i =0 ;i<size;i++)
    {
        if (arr[i]==-1)
        {
            continue;
        }
        else if (arr[i]==page)
        {
         return i;
        }
    }
    return -1;
}//can improve with binary search 
void append(int arr[], int frame, int value)
{
    arr[j]=value;
    j=(j+1)%frame;
}
// 
// FIFO Page Replacement
//
//
void fifoPageRep(int str[], int lstr, int frame )
{
    int arr[frame];
    int pf=0,ph=0;
    memset(arr, -1 , frame*sizeof(int));
    for (int i =0 ;i<lstr;i++)
    {
        if (hit(str[i],arr,frame)>=0)
        {
         //do nothing
            ph+=1;
        }
        else
        {
            append(arr,frame,str[i]);
            //printdist(arr,frame);
            pf+=1;
        }
    }
    printf("Page Hits For FIFO Page Replacement Algorithm %d\n",ph );

    printf("Page Fault For FIFO Page Replacement Algorithm %d\n",pf );
}
//
//
// Corresponding Code for Optimal Page Rep
//
//
int getFirstOccurrence(int page, int str[], int lstr, int position)
{
    for (int i = position ; i< lstr;i++)
    {
        if (str[i]==page)
        {
            return i;
        }
    }
    return lstr;
}
int getDistance(int dist[],int arr[],int str[],  int lstr,int frame, int position)
{
    for (int i =0; i< frame ;i++)
    {
        dist[i] =getFirstOccurrence(arr[i],str,lstr,position) - position;
    }
}
int getMaxPos(int arr[], int frame)
{
    int max=arr[0],maxpos=0;
    for (int i =1 ;i< frame;i++)
    {
        if (arr[i]>max)
        {
            max =arr[i];
            maxpos=i;
        }
    }
    return maxpos;
}
// int getMinPos(int arr[], int frame)
// {
//     int min=arr[0],minpos=0;
//     for (int i =1 ;i< frame;i++)
//     {
//         if (arr[i]<min)
//         {
//             min =arr[i];
//             minpos=i;
//         }
//     }
//     return minpos;
// }
void  optimalPageRep(int str[], int lstr, int frame )
{
    int arr[frame];
    int pf=0,ph=0;
    memset(arr, -1 , frame*sizeof(int));
    for (int i =0 ;i<lstr;i++)
    {
        if (hit(str[i],arr,frame)>=0)
        {
         
            ph+=1;
        }//from here onwards we are only dealing with miss cases so appending is fine
        else 
        {
           if (positionsareempty(arr,frame))
          {
            append(arr,frame,str[i]);
            pf+=1;
            // printf("\nPage faulted %d for %d \n",pf,str[i]);
            // printdist(arr,frame);
          }
          else 
         {
          int dist[frame];
          getDistance(dist,arr,str,lstr,frame,i);
          arr[getMaxPos(dist,frame)]=str[i];
          pf+=1;
          // printf("\npage faulted %d  for %d \n",pf,str[i]);
          // printdist(arr,frame);
         }
        }
    }

    printf("\nPage Hits For Optimal Page Page Replacement Algorithm %d\n",ph);
   
    printf("Page Fault For Optimal Page Replacement Algorithm %d\n",pf );
}
//
// Least Recently Used Algo
//
int getOccurrence(int page, int str[], int lstr, int position)
{
    for (int i = position ; i>=0;i--)
    {
        if (str[i]==page)
        {
            return i;
        }
    }
}
int getRevDistance(int dist[],int arr[],int str[],  int lstr,int frame, int position)
{
    for (int i =0; i< frame ;i++)
    {
        dist[i] =abs(getOccurrence(arr[i],str,lstr,position) - position);
    }
}
void  lruPageRep(int str[], int lstr, int frame )
{
    int arr[frame];
    int pf=0,ph=0;
    memset(arr, -1 , frame*sizeof(int));
    for (int i =0 ;i<lstr;i++)
    {
        int temp=hit(str[i],arr,frame);
        if (temp>=0)
        {
         ph+=1;
        }
        else 
        {
           if (positionsareempty(arr,frame))
          {
            append(arr,frame,str[i]);
            pf+=1;
          }
          else 
         {
          int dist[frame];
          getRevDistance(dist,arr,str,lstr,frame,i);
          arr[getMaxPos(dist,frame)]=str[i];
          pf+=1;
         }
        }
    }
    printf("\nPage Hits For Least Recently Used Page Replacement Algorithm %d\n",ph);
    printf("Page Fault For Least Recently Used Page Replacement Algorithm %d\n",pf );
}
int main()
{
    int lstr,frame;
    printf("Enter the length of the page request string \n");
    scanf("%d",&lstr);
    int str[lstr];
    printf("Enter the pages requested\n");
    for (int i =0 ;i<lstr;i++)
    {
        scanf("%d",&str[i]);
    }
    printf("Enter the number of frames \n" );
    scanf("%d",&frame);
    fifoPageRep(str,lstr,frame);
    j=0; 
    optimalPageRep(str,lstr,frame);
    j=0;
    lruPageRep(str,lstr,frame);
}