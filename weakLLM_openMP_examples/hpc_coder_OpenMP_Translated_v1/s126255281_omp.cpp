#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <omp.h>

using namespace std;

int main (void)
{
	#pragma omp parallel for
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			cout << i << 'x' << j << '=' << i * j
 << endl;		}
	}
}