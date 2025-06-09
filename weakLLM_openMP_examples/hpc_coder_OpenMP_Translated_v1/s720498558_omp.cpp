#include <iostream>
#include <omp.h>

int main(int argc, char **argv){
	#pragma omp parallel for collapse(2)
	for(int i = 1; i < 10; i++){
		for(int j = 1;j < 10; j++){
			std::cout << i << "x" << j << "=" << i * j;
			/* if(!(i == 9 && j == 9)){ */
				std::cout << std::endl;
			/* } */
		}
	}
}