#include <cstdio>
#include <omp.h>

#define N	9

int main()
{
	#pragma omp parallel for
	for(int i = 1; i <= N; i ++)
	{
		for(int j = 1; j <= N; j ++)
		{
			::printf("%dx%d=%d\n", i, j, i * j);
		}
	}
	return(0);
}