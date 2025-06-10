#include <iostream>
#include <vector>
#include <algorithm>
#include <omp.h>
using namespace std;

int main(){
	vector<int> vec_height(10);
	
	for (auto& h : vec_height)
		cin >> h;

	sort(vec_height.begin(), vec_height.end(), greater<int>());
	
	#pragma omp parallel num_threads(4)
	{
		#pragma omp for
		for (int i = 0; i < 3; i++)
			cout << vec_height[i] << endl;
	}
	
    return 0;
}