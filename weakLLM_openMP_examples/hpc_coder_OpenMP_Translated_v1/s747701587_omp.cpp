#include<stdio.h>
#include<omp.h>

int main()
{
	int a[9], b[9];
	for(int i = 0;i < 9;i++)
	{
		a[i] = i + 1;
		
		#pragma omp parallel for
		for(int j = 0;j < 9;j++)
		{
			b[j] = j + 1;
			printf("%dx%d=%d\n",a[i],b[j],a[i]*b[j]);
		}
	}

	return 0;
}