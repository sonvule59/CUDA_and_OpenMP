#include<iostream>
#include <string>
#include <omp.h>
using namespace std;

int main(){
	string str;
	#pragma omp parallel for
	for(int i = 1; i < 10; ++i)
	{
		for(int j = 1; j < 10; ++j)
		{
			cout << i << 'x' << j << "=" << i * j << endl;
		}
	}
    return 0;
}