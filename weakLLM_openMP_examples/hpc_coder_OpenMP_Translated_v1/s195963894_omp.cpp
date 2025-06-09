#include <stdio.h>
#include <omp.h>

int main(void)
{
	int array[9][9];
	int i,j;
	
	#pragma omp parallel for collapse(2)
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			array[i][j]=(i+1)*(j+1);
			printf("%dx%d=%d\n",i+1,j+1,array[i][j]);
		}
	}
	
	return 0;
}