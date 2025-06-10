#include <algorithm>
#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    std::vector<int> hills;
    
    int n;
    while (std::cin >> n) {
        hills.push_back(n);
    }
    
    std::sort(hills.begin(), hills.end(), std::greater<int>());
    
#pragma omp parallel for
    for (int i = 0; i < 3; ++i) {
        std::cout << hills[i] << std::endl;
    }
    
    return 0;
}