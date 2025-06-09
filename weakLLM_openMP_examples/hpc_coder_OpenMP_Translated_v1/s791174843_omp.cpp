#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    #pragma omp parallel for
    for(int r = 1; r <= 9; r++) {
        for(int c = 1; c <= 9; c++) {
            cout << r << "x" << c << "=" << r * c << endl;
        }
    }
    
    return(0);
}