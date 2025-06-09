#include<stdio.h>
#include<omp.h>

int main(){

	int multiply1;
	int multiply2;

	#pragma omp parallel for private(multiply1, multiply2)
	for(multiply1 = 1; multiply1 <= 9; multiply1++)
	{
		for(multiply2 = 1; multiply2 <= 9; multiply2++)
		{
			printf("%dx%d=%d\n", multiply1, multiply2, 
				multiply1*multiply2);
		}
	}
    return 0;
}