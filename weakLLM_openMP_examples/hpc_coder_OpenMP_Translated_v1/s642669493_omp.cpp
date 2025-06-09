#include<iostream>
#include<omp.h>
using namespace std;

int main(){
	#pragma omp parallel for
	for (long long i=1;i<=9;i++){
		for (long long j=1;j<=9;j++){
		cout << i << "x" << j << "=" << i*j << endl;
		if (j==9){
		break;}
		}
	}
    return 0;
}