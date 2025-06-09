#include <iostream>
#include <string>
#include <omp.h>

using namespace std;

int 
main()
{
	int i = 0, j = 0;

	#pragma omp parallel for private(i, j)
	for ( i = 1 ; i < 10 ; i = i + 1 )
	{
		for ( j = 1 ; j < 10 ; j = j + 1 )
		{
			cout << i << "x" << j << "=" << i*j << endl;
		}
	}
	return 0;
}