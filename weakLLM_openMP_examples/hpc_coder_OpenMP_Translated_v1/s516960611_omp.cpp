#include <cstdio>
#include <omp.h>

int main()
{
#pragma omp parallel for
	for(int i = 1; i <= 9; i ++)
	{
		for(int j = 1; j <= 9; j ++)
		{
			::printf("%dx%d=%d\n", i, j, i * j);
		}
	}
}