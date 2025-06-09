#include <iostream>
#include <omp.h>
using namespace std;

int main() {
	int i; //x*y???x??¨?????¨
	int k; //x*y???y??¨?????¨
	int seki = 0; //?????¨?????¨
	
	#pragma omp parallel for
	for(i=1;i<=9;i++){
		for(k=1;k<=9;k++){
			seki = i * k; 
			std::cout << i;
			std::cout << "x";
			std::cout << k;
			std::cout << "=";
			std::cout << seki;
			std::cout << "\n";
		}
	}
	
	return 0;
}