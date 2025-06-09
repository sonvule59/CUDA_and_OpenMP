#include <iostream>
#include <omp.h>
using namespace std;

int main(void) {
    #pragma omp parallel for
    for(int i = 1; i <= 9; ++i) {
        for(int j = 1; j <= 9; ++j) {
            cout << i << "x" << j << "=" << i*j << endl;
        }
    }
}