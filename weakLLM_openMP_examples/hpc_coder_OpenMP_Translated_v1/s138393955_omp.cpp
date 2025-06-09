#include <iostream>
#include <omp.h>

using namespace std;

int main() {

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int n1 = i + 1;
            int n2 = j + 1;
            cout << to_string(n1) + "x" + to_string(n2) + "=" + to_string(n1 * n2) << endl;

        }
    }

    return 0;
}

The OpenMP code uses the `#pragma omp parallel for collapse(2)` directive to parallelize the nested loops. The `collapse(2)` clause tells OpenMP to collapse the two loops into a single parallel loop, which can improve performance.