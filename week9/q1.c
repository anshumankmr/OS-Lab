#include <stdio.h>
#include <string.h>

int proc,res;
int Request(int request[], int need[proc][res],int pos)
{
 for (int i = 0;i<res;i++)
 {
 	if (request[i]>need[pos][i])
 	{
 		return 0;
 	}
 }
 return 1;
}
int requestIsCompatible(int request[], int avail[])
{
	for (int i =0 ;i<res;i++)
	{
		if (request[i]>avail[i])
		{
			//printf("request[i] %d avail[i]%d \n",request[i] ,avail[i] );
			return 0;

		}
	}
	return 1;
}
void vectoradd(int avail[], int need[proc][res], int pos)
{
	for (int i = 0 ; i< res;i++)
	{
		avail[i]+=need[pos][i];
	}
}
void printMatrix(int matrix[proc][res])
{
	for (int i =0;i<proc;i++)
	{
		for (int j =0 ; j<res;j++)
		{
			printf("%d ",matrix[i][j] );
		}
		printf("\n");
	}
}
int findAnIndex(int avail[], int need[proc][res], int finish[])
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
         if (need[i][j]>avail[j])
         {
         	//printf("\n%d %d\n",need[i][j],avail[j] );
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
void resourceRequest(int need[proc][res],int max[proc][res],int alloc[proc][res],int avail1[], int finish[])
{
	int request[res];
    printf("\nEnter the request vector \n");
    for (int i = 0;i<res;i++)
    {
     scanf("%d",&request[i]);
    }
    printf("\nEnter which process wishes to request the resource\n");
    int temp1;
    scanf("%d",&temp1);
    finish[temp1]=0;
	int pos1=Request(request,need,temp1);
      printf("Pos %d \n",pos1 );
      if (pos1!=-1)
      {
      	if (requestIsCompatible(request,avail1))
        {
     	  for (int i = 0;i<res;i++)
     	  {
     	  	avail1[i]-=request[i];
     		alloc[pos1][i]+=request[i];
     		need[pos1][i]-=request[i];
     	  } // end for 
     	  printf("The system will be safe\n"); 
     	  printf("Need Matrix\n");
     	  printMatrix(need);
     	  printf("Allocation Matrix\n");
     	  printMatrix(alloc);
     	  printf("Maximum Matrix\n");
     	  printMatrix(max);
         }// end request is compatible
        else
        {
          printf("The system won't be safe\n");	
        }// else case for request is compatible
      } 
      else
      {
      	printf("System won't be safe \n");
      }
      finish[temp1]=1;
}
int main()
{
    printf("Enter the number of resources \n");
    scanf("%d",&res);
    printf("Enter the number of processes\n");
    scanf("%d",&proc);
    int need[proc][res],max[proc][res],alloc[proc][res],avail[res];
    for (int i = 0;i< proc;i++)
    {
        printf("Enter the number of instances allocated to  Process P%d\n",i );
    	for (int j=0;j<res;j++)
    	{
            printf("Resource R%d ",j );
    		scanf("%d",&alloc[i][j]);
    		//need[i][j]=max[i][j]-alloc[i][j];
    	}
        printf("\n");
    }
   printf("\n Enter the total number of resources of the instance for each process\n");

      for (int i = 0;i< proc;i++)
    {
                printf("Process P%d\n",i );

    	for (int j=0;j<res;j++)
    	{
            printf("Resource R%d ",j );
    		scanf("%d",&max[i][j]);
    		need[i][j]=max[i][j]-alloc[i][j];
    	}
        printf("\n");
    }
    int avail1[res];
    printf("Enter the available vector\n");
    for (int i = 0;i< res;i++)
    {
    	scanf("%d",&avail[i]);
    	avail1[i]=avail[i];
    }
    printf("Need Matrix\n");
    printMatrix(need);
    printf("Safe Sequence\n");
    int finish[proc];
    int temp=proc;
    memset(finish,0,proc*sizeof(int));
    while (temp>0)
    {
     int pos= findAnIndex(avail,need,finish);
     if (pos==-1)
     {
     	printf("\nSafe Sequence Not Possible \n");
     	break;
     }
     printf("%d ",pos);
     vectoradd(avail,need,pos);
     //makezero(need,pos);
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
    }
    resourceRequest(need,max,alloc,avail1,finish);
    resourceRequest(need,max,alloc,avail1,finish);
    resourceRequest(need,max,alloc,avail1,finish);
}
