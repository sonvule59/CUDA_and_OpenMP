#include <bits/stdc++.h>
#define cinf(n,x) for(int i=0;i<(n);i++) cin >> x[i];
typedef long long int ll;
using namespace std;

int main(){
#pragma omp parallel for
	for(int i=1;i<10;i++){
		for(int j=1;j<10;j++){
			cout << i<<"x"<<j<<"="<< i*j<<endl;
		}
	}
}