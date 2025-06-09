#include "iostream"
#include "omp.h"
using namespace std;

int main(){

	int mplication, mplicand;

	#pragma omp parallel for private(mplication, mplicand)
	for (int mplication = 1; mplication <= 9; ++mplication)
	{
		for (int mplicand = 1; mplicand <= 9; ++mplicand)
		{
			cout << mplication << "x" << mplicand << "=" << mplication * mplicand << endl;
		}
	}

    return 0;
}