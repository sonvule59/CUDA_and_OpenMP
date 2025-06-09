#include <bits/stdc++.h>
#include <omp.h>
using namespace std;
long long a,b;
int main(){
	#pragma omp parallel for
	for(a=1;a<=9;a++){
		for(b=1;b<=9;b++){
			cout<<a<<"x"<<b<<"="<<a*b<<endl;
		}
	}
}