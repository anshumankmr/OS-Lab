#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char str[1000];
	int n;
	int c=0;
	int *s;
	int pf=0;
	int i,j;
	printf("Enter sample  page string ");
    scanf("%s",str);
    printf("Enter the number of page slots \n");
    scanf("%d",&n);
    s = (int*)malloc(n*sizeof(int));
    memset(s,-1,n*sizeof(int));
    int a,f;
    for (i =0 ; i<strlen(str);i++)
    {
    	a = str[i]-'0';
    	f=0;
    	for (j=0;j<n;j++)
    	{
    		if (a==s[j])
    		{
    			f=1;
    			break;
    		}
    		if (!f)
    		{
    			pf++;
    			s[c++]=a;
    			c%=n;
    			printf("\nPage slots status \n");
    			for (int k=0;k
    				<n;k++)
    			{
    				printf("%d ",s[k] );
    			}
    			printf("\nNumber of page faults  %d \n",pf );

    		}
    	}
    }
    free(s);
}