#include<iostream>
#include<omp.h>
using namespace std;

int main() {

    #pragma omp parallel for
    for (int i = 1; i <= 9; i++){
        cout << i << "x1=" << i*1 << endl;
        cout << i << "x2=" << i*2 << endl;
        cout << i << "x3=" << i*3 << endl;
        cout << i << "x4=" << i*4 << endl;
        cout << i << "x5=" << i*5 << endl;
        cout << i << "x6=" << i*6 << endl;
        cout << i << "x7=" << i*7 << endl;
        cout << i << "x8=" << i*8 << endl;
        cout << i << "x9=" << i*9 << endl;
    }
    return 0;
}