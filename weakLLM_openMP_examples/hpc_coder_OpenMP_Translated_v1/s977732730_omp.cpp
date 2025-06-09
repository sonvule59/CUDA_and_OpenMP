#include <iostream>
#include <omp.h>

using namespace std;

int main(){
    
    #pragma omp parallel for
    for (int m = 1; m <= 9; m++) {
        for (int n = 1; n <= 9; n++) {
            int result;
            
            result = n * m;
            cout << m << "x" << n << "=" << result << endl;
        }
    }
    
    return 0;
}