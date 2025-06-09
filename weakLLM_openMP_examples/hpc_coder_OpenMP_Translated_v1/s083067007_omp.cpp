#include <bits/stdc++.h>
#include <omp.h>
using namespace std;

#define for_(i,a,b) for(int i=(a);i<(b);++i)

int main() {
	#pragma omp parallel for
	for_(i,1,10) {
		for_(j,1,10) {
			cout << i << "x" << j << "=" << i * j << endl;
		}
	}
}