#include <iostream>
#include <string>
#include <omp.h>

using namespace std;
int main()
{
	int a=1,b=1;
	#pragma omp parallel for
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<a<<"x"<<b<<"="<<a*b<<endl;
			b++;
		}
		b=1;
		a++;
	}
	return 0;
}