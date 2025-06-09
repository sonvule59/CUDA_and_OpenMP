#include<iostream>
#include<omp.h>
using namespace std;

int main(void)
{
	int l, r;
	#pragma omp parallel for
	for(int i = 0; i < 81; i++)
	{
		l = i/9+1;
		r = i%9+1;
		cout << l << 'x' << r << '=' << l*r << endl;
	}
	return 0;
}