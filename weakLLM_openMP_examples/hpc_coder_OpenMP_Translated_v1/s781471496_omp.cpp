#include<iostream>
#include<omp.h>
using namespace std;

int main() {
        int m1, m2;
        m1 = 1;
        m2 = 1;
#pragma omp parallel for
        for (m1; m1 < 10; m1++) {
                for (m2; m2 < 10; m2++) {
                        cout << m1 << "x" << m2 << "=" << m1*m2 << endl;
                }
m2 = 1;
        }
        return 0;
}