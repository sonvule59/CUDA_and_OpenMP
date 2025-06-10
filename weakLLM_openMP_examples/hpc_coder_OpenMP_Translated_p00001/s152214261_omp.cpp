#include <iostream>
#include <algorithm>
#include <omp.h>
using namespace std;
#define rep(i,a) for(int i = 0 ; i < a ; i ++)
int main(void){
	int h[10];
	rep(i,10)cin>>h[i];
	sort(h,h+10);
	#pragma omp parallel num_threads(3)
	{
		#pragma omp for
		for(int i = 0 ; i < 3 ; i ++)
			cout<<h[10-i-1]<<endl;
	}
}