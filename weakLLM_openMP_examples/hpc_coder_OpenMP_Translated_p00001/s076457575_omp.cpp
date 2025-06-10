#include <iostream>
#include <vector>
#include <algorithm>
#include <omp.h>

using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)

int main(){

	vector<int> data(10);

	rep(i,10){
		cin >> data[i];
	}

	sort(data.begin(),data.end());

	#pragma omp parallel num_threads(3)
	{
		#pragma omp for
		for(int i = 0; i < 3; i++){
			cout << data[9 - i] << endl;
		}
	}


	return 0;
}