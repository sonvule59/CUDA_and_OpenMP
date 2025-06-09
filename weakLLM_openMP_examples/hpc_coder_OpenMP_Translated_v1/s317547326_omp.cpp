#include <cstdio>
#include <omp.h>
using namespace std;

int main(){
    #pragma omp parallel for
    for(int x = 1; x < 10; x++){
       for(int y = 1; y < 10; y++){
           printf("%dx%d=%d\n", x, y, x*y);
       }
    }
    return 0;
}