#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
	int X, Y;
	#pragma omp parallel for private(X,Y)
	for (X = 1; X < 10; X++)
	{
		for (Y = 1; Y < 10; Y++)
		{
			printf("%dx%d=%d\n", X,Y,(X*Y));
		}
	}
	return 0;
}