#include<iostream>
#include<algorithm>
#include<omp.h>
using namespace std;
int main(){
	int yaaa[10];
	for(int i=0;i<10;i++){
		cin >> yaaa[i];
	}
	sort(&yaaa[0],&yaaa[10]);
	#pragma omp parallel for
	for(int i=0;i<3;i++){
	cout <<yaaa[9-i]<<endl;
}
}