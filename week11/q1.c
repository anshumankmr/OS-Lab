#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    return 0;
}//can improve with binary search 
void append(int arr[], int frame, int value)
{
    arr[j]=value;
    j=(j+1)%frame;
}
void fifoPageRep(int str[], int lstr, int frame )
{
    int arr[frame];
    int pf=0;
    memset(arr, -1 , frame*sizeof(int));
    for (int i =0 ;i<lstr;i++)
    {
        if (hit(str[i],arr,frame))
        {
         //do nothing
        }
        else
        {
            append(arr,frame,str[i]);
            pf+=1;
        }
    }
    printf("Page Fault For FIFO Page Replacement Algorithm %d\n",pf );
}
// Corresponding Code for Optimal Page Rep
int getFirstOccurrence(int page, int str[], int lstr, int position)
{
    for (int i = position+1 ; i< lstr;i++)
    {
        if (str[i]==page)
        {
            return (i);
        }
    }
    return (lstr-1);
}
int getDistance(int dist[],int arr[],int str[], int page, int lstr,int frame, int position)
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
int getMinPos(int arr[], int frame)
{
    int min=arr[0],minpos=0;
    for (int i =1 ;i< frame;i++)
    {
        if (arr[i]<min)
        {
            min =arr[i];
            minpos=i;
        }
    }
    return minpos;
}
// void printdist(int arr[], int frame)
// {
//     printf("Frame Table\n");
//     for (int i =0;i<frame;i++)
//     {
//         printf("%d ", arr[i]);
//     }
// }
// //can use this for verification
void  optimalPageRep(int str[], int lstr, int frame )
{
    int arr[frame];
    int pf=0;
    memset(arr, -1 , frame*sizeof(int));
    for (int i =0 ;i<lstr;i++)
    {
        if (hit(str[i],arr,frame))
        {
         //do nothing
        }//from here onwards we are only dealing with miss cases so appending is fine
        else 
        {
           if (i>=0  && i<= frame-1)//need to fix for certain other use cases potential fix positionsareempty(arr,frame)?
          {
            append(arr,frame,str[i]);
            pf+=1;
            // printf("\nPage faulted %d for %d \n",pf,str[i]);
            // printdist(arr,frame);
          }
          else 
         {
          int dist[frame];
          int page=str[i];
          getDistance(dist,arr,str,page,lstr,frame,i);
          arr[getMaxPos(dist,frame)]=str[i];
          pf+=1;
          // printf("\npage faulted %d  for %d \n",pf,str[i]);
          // printdist(arr,frame);
         }
        }
    }
    printf("Page Fault For Optimal Page Replacement Algorithm %d\n",pf );
}
// Least Recently Used Algo
void  lruPageRep(int str[], int lstr, int frame )
{
    int arr[frame], count[frame];
    int pf=0;
    memset(arr, -1 , frame*sizeof(int));
    memset(count, 0 , frame*sizeof(int));
    for (int i =0 ;i<lstr;i++)
    {
        int temp=hit(str[i],arr,frame);
        if (temp)
        {
         count[temp]+=1;
        }
        else 
        {
           if (positionsareempty(arr,frame))
          {
            count[j]+=1;
            append(arr,frame,str[i]);
            pf+=1;
          }
          else 
         {
          int pos =getMinPos(count,frame);
           arr[pos]=str[i];
           count[pos]=0;
           pf+=1;
         }
        }
    }
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