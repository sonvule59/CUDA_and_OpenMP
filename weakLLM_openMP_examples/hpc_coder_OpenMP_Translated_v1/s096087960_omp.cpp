#include<iostream>
#include<omp.h>
using namespace std;
int main()
{
	int i,k;
	#pragma omp parallel for private(i,k)
	for(i=1;i<10;i++)
		for(k=1;k<10;k++)
			{
				cout<<i<<"x"<<k<<"="<<i*k<<endl;
			}
}