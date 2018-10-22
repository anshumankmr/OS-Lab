#include <stdio.h>
void getPhysical(int seg, int byte,int startpos[],int endpos[],int n)
{
	if (endpos[seg]- startpos[seg] >=byte )
	{
		printf(" Location %d \n",startpos[seg]+byte-1);
	}
}
int main()
{
	// int physmem;
	// printf("Enter the total size of physical memory \n");
 //    scanf("%d",&physmem);
    printf("Enter the number of segments\n");
    int n;
    scanf("%d",&n);
    int startpos[n],endpos[n];
    for (int i= 0;i<n;i++)
    {
    	printf("Enter the size of segment %d \n",i );
    	int temp;
    	scanf("%d",&temp);
    	printf("Enter the starting location of segment %d \n",i );
        scanf("%d",&startpos[i]);
        
        endpos[i]=startpos[i]+temp-1;
    }
    printf("Enter the segment\n");
    int byte,seg;
    scanf("%d",&seg);
    printf("Enter the number of bytes\n");
    scanf("%d",&byte);
    getPhysical(seg,byte,startpos,endpos,n);
}   