#include <iostream>
#include <omp.h>
using namespace std;
int main(void){
    int x,y,z;
    z=0;
    x=0;
    #pragma omp parallel for
    for(x=0;x<10;x++){
        for(z=0;z<10;z++){
            y=x*z;
            cout<<x<<"x"<<z<<"="<<y<<endl;
        }
    }
}