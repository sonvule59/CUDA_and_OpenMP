#include <iostream>
#include <omp.h>
using namespace std;

int main() {
	int i,n,ans;
	#pragma omp parallel for private(i,n,ans)
	for(i=1;i<=9;i++){
		for(n=1;n<=9;n++){
			ans =i * n;
			cout << i << "x" << n << "=" << ans << endl;
		}
	}
	return 0;
}