#include <iostream>
#include <omp.h>
using namespace std;
int main(void){
    int x,y,z;
    #pragma omp parallel for private(x,y,z)
    for(x = 1; x < 10; x++){
        for(y = 1; y < 10; y++){
            z = x*y;
            std::cout << x << "x"<< y << "=" <<z<< std::endl;
        }
    }
}