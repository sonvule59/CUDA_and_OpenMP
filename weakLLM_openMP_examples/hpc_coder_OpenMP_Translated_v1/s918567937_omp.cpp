#include <iostream>
#include <omp.h>
using namespace std;
int main()
{
	int i,j;
	#pragma omp parallel for private(i,j)
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			cout << (i + 1) << "x" << (j + 1) <<"="<<((i + 1) * (j + 1))<<endl;
		}
	}
	return 0;
}