#include <algorithm>
#include <iostream>
#include <omp.h>

int main() {
	int h[10];

	for (int i = 0; i < 10; i++)
		std::cin >> h[i];

	std::sort(h, h + 10);

	#pragma omp parallel num_threads(4)
	{
		#pragma omp for
		for (int i = 0; i < 10; i++)
			std::cout << h[i] << std::endl;
	}
}