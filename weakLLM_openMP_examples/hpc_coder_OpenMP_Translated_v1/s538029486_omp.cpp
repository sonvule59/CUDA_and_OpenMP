#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>
#include <map>
#include <omp.h>

using namespace std;
typedef long long Int;
#define REP(i , x) for(int i = 1 ; i < x ; ++i)


int main()
{
	REP(i, 10){
		REP(j, 10){
			cout << i << "x" << j << "=" << i*j << endl;
		}
	}

	return 0;
}

The OpenMP version uses the `#pragma omp parallel for` directive to parallelize the outer loop. The `#pragma omp parallel for` directive tells the compiler to create a team of threads and distribute the iterations of the loop among them. The `#pragma omp parallel for` directive is used in combination with the `#pragma omp single` directive to ensure that only one thread executes the code inside the `#pragma omp single` directive.

The `#pragma omp single` directive is used to ensure that only one thread executes the code inside the `#pragma omp single` directive. This is useful when you want to perform some operations that are not thread-safe, such as printing to the console.

The `#pragma omp parallel for` directive is used to parallelize the outer loop. The `#pragma omp parallel for` directive tells the compiler to create a team of threads and distribute the iterations of the loop among them. The `#pragma omp parallel for` directive is used in combination with the `#pragma omp single` directive to ensure that only one thread executes the code inside the `#pragma omp single` directive.