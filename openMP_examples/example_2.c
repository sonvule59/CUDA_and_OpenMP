#include <stdio.h>
int dummyMethod1();
int dummyMethod2();
int dummyMethod3();
int dummyMethod4();

const int n =20;

int main() {
	int a[n];
	int b=1000;
    int i;
    dummyMethod1();
    #pragma omp parallel for private(i)
    #pragma rose_outline
	for (i = 0; i < n; ++i)
	{
		a[i]=b+i;
	}
dummyMethod2();
printf("gjggghjjhj");
return 0;
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