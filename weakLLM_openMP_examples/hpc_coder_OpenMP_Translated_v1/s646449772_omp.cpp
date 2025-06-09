#include <iostream>
#include <omp.h>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    #pragma omp parallel for
    for(int i = 1; i < 10; i++){
        for( int j = 1; j < 10; j++){
            cout << i << "x" << j << "=" << i * j << "\n";
        }
    }
    

    return 0;
}