#include<stdio.h>
#include<omp.h>
int main()
{
	int n,m,i,j;
	#pragma omp parallel for private(i,j)
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=9;j++)
		{
			printf("%dx%d=%d\n",i,j,i*j);
		}
	}
}