#include <stdlib.h>
#include <stdio.h>
int dummyMethod1();
int dummyMethod2();
int dummyMethod3();
int dummyMethod4();
int main(int argc, char * argv[])
{
	int i, j;
	int n = 1000, m = 1000;
	double b[1000][1000];
	int _ret_val_0;

	dummyMethod1();
	for (i=0; i<n; i ++ )
	{
		#pragma omp parallel for private(j)
//#pragma rose_outline
		for (j=0; j<m; j ++ )
		{
			b[i][j]=0.5;
		}
	}
	dummyMethod2();

	for (i=1; i<n; i ++ )
	{
			dummyMethod1();
		for (j=1; j<m; j ++ )
		{
			b[i][j]=b[i-1][j-1];
		}
			dummyMethod2();
	}
	printf("b[500][500]=%f\n", b[500][500]);
	_ret_val_0=0;
	return _ret_val_0;
}
int dummyMethod1(){
    return 0;
}
int dummyMethod2(){
    return 0;
}
int dummyMethod3(){
    return 0;
}
int dummyMethod4(){
    return 0;
}