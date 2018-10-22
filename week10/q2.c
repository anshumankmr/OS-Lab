#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int countBits( int number) 
{       
      return ceil((float)log2(number)+1); 
} 
// int isPowerOfTwo(int n) 
// { 
//    if (n == 0) 
//     return 0; 
//   while (n != 1) 
//   { 
//       if (n%2 != 0) 
//          return 0; 
//       n = n/2; 
//   } 
//   return 1; 
// } 
 void willitfit(int page,int pagesize, int mem)
{
	if (page>=mem)
	{
		printf("invalid\n");
	}
	else
	{
		printf("Page Number %d \n",page/pagesize);
		printf("Page Offset %d \n",page%pagesize);
		printf("Bytes Required to represent page number and offset respectively %d %d\n",ceil((float)countBits(page/pagesize)/8), countBits(page%pagesize)%8);
	}
}
int main()
{
	printf("Enter the size of a page \n");
	int page;
	scanf("%d",&page);
	printf("Enter the number of pages \n");
	int number;
	scanf("%d",&number);
	// if (isPowerOfTwo(page) && isPowerOfTwo(number))
	// {
	// 	printf("Invalid Values\n");
	// 	exit(0);
	// }
	printf("Enter position \n");
	int pos;
	scanf("%d",&pos);
    willitfit(pos,page,page*number);
}