#include <stdio.h>
#include <stdlib.h>

void sortit (int mempart[], int m)
{
	int temp;
	for (int i=0; i<m; i++)
	{
		for (int j=i; j<m; j++)
		{
			if (mempart[i]<mempart[j])
			{
				temp = mempart[i];
				mempart[i] = mempart[j];
				mempart[j] = temp;
			}
		}
	}
}

int main ()
{
	int m = 6, p = 5;
	int mempart[6] = {300, 600, 350, 200, 500, 125};
	int process[5] = {115, 550, 358, 200, 275};
	int alloc[6];
	int finish[5];
	for (int i=0; i<6; i++)
		{alloc[i] = -1;
					}
	for (int i=0; i<5; i++)
		{finish[i] = -1;
					}
	sortit(mempart, m);
	//my ref
	int found = 0;
	/*for (int i=0; i<6; i++)
		printf("%d\n", mempart[i]);
	*/for (int cnt = 0; cnt<m; cnt++)
	{
		for (int i=0; i<p; i++)
		{
			if (finish[i] == 1)
			{
				continue;
			}
			if (mempart[cnt] >= process[i])
			{
				
				printf("process %d allocated block with size %d\n", i, mempart[cnt]);
				alloc[cnt] = i;
				mempart[cnt]-=process[i];
				finish[i] = 1;
				found = 1;	
				sortit(mempart, m);
			}

		}
	}
	for (int i=0; i<5; i++)
	{
		if (finish[i]!=1)
			printf("process %d wasn't allocated a block\n",i );
	}
	return 0;
}