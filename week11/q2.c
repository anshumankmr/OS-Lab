#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int j=0;

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
}
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
void append(int arr[], int frame, int value)
{
    arr[j]=value;
    j=(j+1)%frame;
}
void secondchance(int str[], int lstr, int m)
{
    int modified[m],pf=0,ph=0, arr[m];
    memset(arr,-1,m*sizeof(int));
    memset(modified,0,m*sizeof(int));
    for (int i = 0 ; i < lstr; i++ )
    {
     int temp=hit(str[i],arr,m);
     if (temp>=0)
     {
      modified[temp]=1;
      ph+=1;
     }
     else
     {
        if (positionsareempty(arr,m))
        {
            modified[j]=1;
            append(arr,m,str[i]);
            pf+=1;
        }
        else
        {
            int position = -1 ;
            for (int k = 0; k<m;k++)
            {
                if (modified[k] ==1 )
                {
                    modified[k]=0;
                    if (position == -1 )
                    {
                     position=k;
                    }
                }
                else
                {
                  position = k;
                  break;
                }
            }
            arr[position]=str[i];
            modified[position]=1;
            pf+=1;
        }
     }
    }
    printf("\nPage Hits For Second Chance Page Replacement Algorithm %d\n",ph);
    printf("Page Fault For Second Chance Page Replacement Algorithm %d\n",pf );

}

int main()
{
    int lstr,m;
    printf("Enter the length of the page request string \n");
    scanf("%d",&lstr);
    int str[lstr];
    printf("Enter the pages requested\n");
    for (int i =0 ;i<lstr;i++)
    {
        scanf("%d",&str[i]);
    }
    printf("Enter the number of frames \n" );
    scanf("%d",&m);
    secondchance(str,lstr,m);
}