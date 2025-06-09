#include<iostream>
#include<omp.h>
using namespace std;

int main(){
	#pragma omp parallel for
	for (int i = 1; i <= 9; i++)
	{
		for (size_t j = 1; j <= 9; j++)
		{
			int ans = i * j;
			cout << i << "x" << j << "=" << ans << endl;
		}
	}
    return 0;
}