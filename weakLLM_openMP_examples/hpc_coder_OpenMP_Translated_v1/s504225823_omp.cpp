#include <iostream>
#include <omp.h>
using namespace std;
int main(){
    int i,o,s;
    #pragma omp parallel for private(i,o,s)
    for(i=1;i<=9;i++){
        for(o=1;o<=9;o++){
            s=i*o;
            cout<<i<<"x"<<o<<"="<<s<<endl;
        }
    }
}