#include <iostream>
#include <omp.h>
using namespace std;
 
int main()
{
	#pragma omp parallel for
	for(int a =1;a<10;a++)
		for(int b =1;b<10;b++)
			cout<<a<<"x"<<b<<"="<<a*b<<endl;
	return 0;
}