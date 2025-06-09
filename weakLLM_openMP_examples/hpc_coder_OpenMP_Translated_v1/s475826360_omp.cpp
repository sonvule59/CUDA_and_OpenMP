#include <iostream>
#include <omp.h>
using namespace std;
#define N 9

int main(){
    #pragma omp parallel for
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout << i << "x" << j << "=" << (i*j) << "\n";
        }
    }
    return 0;
}