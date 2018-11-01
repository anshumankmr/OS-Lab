#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int j;
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
         return 1;
        }
    }
    return 0;
}
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
    return (lstr);
}
int getDistance(int dist[],int str[], int page, int lstr,int frame, int position)
{
    for (int i =0; i< frame ;i++)
    {
        dist[i] =getFirstOccurrence(page,str,lstr,position) - position;
    }
}
int getMaxPos(int dist[], int frame)
{
    int max=dist[0],maxpos=0;
    for (int i =1 ;i< frame;i++)
    {
        if (dist[i]>max)
        {
            max =dist[i];
            maxpos=i;
        }
    }
    return maxpos;
}
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
        }
        else if (i>=0||i<= frame-1)
        {
            append(arr,frame,str[i]);
            pf+=1;
        }
        else 
        {
            int dist[frame];
            int page=str[i];
            getDistance(dist,str,page,lstr,frame,i);
            arr[getMaxPos(dist,frame)]=str[i];
            pf+=1;
        }
    }
    printf("Page Fault For Optimal Page Replacement Algorithm %d\n",pf );
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
}