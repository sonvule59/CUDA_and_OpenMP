#include <iostream>
#include <omp.h>

int main() {
    #pragma omp parallel for
    for( int i = 1 ; i <= 9 ; i++ ) {
        for( int ii = 1 ; ii <= 9 ; ii++ ) {
            std::cout << i << "x" << ii << "=" << i * ii << std::endl ;
        }
    }
}