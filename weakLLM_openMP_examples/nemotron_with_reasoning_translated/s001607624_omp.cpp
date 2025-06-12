#include<omp.h>
#include<iostream>

int main() {
    for(int i = 1; i < 10; ++i) {
        #pragma omp parallel for
        for(int j = 1; j < 10; ++j) {
            cout << i << "x" << j << "=" << i * j << std::endl;
        }
    }
    cout << std::endl;
}