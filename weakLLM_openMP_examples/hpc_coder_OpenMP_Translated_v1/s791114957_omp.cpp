#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    int x, y;
    string str;
    #pragma omp parallel for private(x, y)
    for(x = 1; x < 10; x++){
        for(y = 1; y < 10; y++){
            str = to_string(x) + "x" + to_string(y) + "=" + to_string(x*y);
            cout << str << endl;
        }
    }
}