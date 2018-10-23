#include <stdio.h>
#include <stdlib.h>
int proc,res;
void memoryset(int finish[], int allocation[proc][res] )
{
    int temp;
    for ( int  i =0 ;i<proc;i++)
    {
        temp=0;
        for (int j=0 ; j <res;j++)
        {
            //printf("allocation%d ",allocation[i][j] );
            if (allocation[i][j]!=0)
            {
                temp=1;
                break;
            }
        }
        if (temp==1)
        {
            finish[i]=0;
        }
        else
        {
            finish[i]=1;
        }
    }
}
void vectoradd(int avail[], int allocation[proc][res], int pos)
{
	for (int i = 0 ; i< res;i++)
	{
		avail[i]+=allocation[pos][i];
	}
}
int findAnIndex(int avail[], int request[proc][res], int finish[])
{
	int temp;
	for (int i = 0;i<proc;i++)
	{
		temp=0;
		if (finish[i]==1)
		{
			//printf("\nSkipping %d \n",i );
			continue;
		}
		for (int j = 0; j <res;j++)
		{
         if (request[i][j]>avail[j])
         {
         	//printf("\n%d %d\n",request[i][j],avail[j] );
         	temp=1;
         	break;
         }
		}
		if (temp==1)
		{
			continue;
		}
		else
		{
			//printf("index to return%d\n",i  );
			return i;
		}
	}
	return -1;
}

int main()
{
    printf("Enter the number of resources \n");
    scanf("%d",&res);
    printf("Enter the number of processes\n");
    scanf("%d",&proc);
    int request[proc][res],allocation[proc][res],avail[res];
    printf("Enter allocation matrix\n");
    for (int i = 0;i< proc;i++)
    {
        printf("Process P%d\n",i );
    	for (int j=0;j<res;j++)
    	{
            printf("Resource R%d ",j );
    		scanf("%d",&allocation[i][j]);
    		//request[i][j]=max[i][j]-allocation[i][j];
    	}
        printf("\n");
    }
   printf("Enter Request Matrix\n");

      for (int i = 0;i< proc;i++)
    {
                printf("Process P%d\n",i );

    	for (int j=0;j<res;j++)
    	{
            printf("Resource R%d ",j );
    		scanf("%d",&request[i][j]);
    		//request[i][j]=max[i][j]-allocation[i][j];
    	}
        printf("\n");
    }
    printf("Enter the available vector\n");
    for (int i = 0;i< res;i++)
    {
    	scanf("%d",&avail[i]);
    }
    // printf("request Matrix\n");
    // //printMatrix(request);
    printf("Safe Sequence\n");
    int finish[proc];
    int temp=proc;
    memoryset(finish,allocation);
    while (temp>0)
    {
     int pos= findAnIndex(avail,request,finish);
     if (pos==-1)
     {
     	printf("\nSafe Sequence Not Possible \n");
     	break;
     }
     printf("%d ",pos);
     vectoradd(avail,allocation,pos);
     //makezero(request,pos);
     finish[pos]=1;
     temp--;
    }
    if (temp==0)
    {
      printf("\nSince all the processes are now complete, the system is safe ");     
    }
    else
    {
    	printf("\nThe system is not safe");
    	exit(0);
    }
}
