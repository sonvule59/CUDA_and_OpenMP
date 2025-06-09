#include<iostream>
#include<omp.h>
using namespace std;

int main(){
    enum{
        STARTMULTITABLE = 1,
        ENDMULTITABLE = 9
    };
    
    int i;
    #pragma omp parallel for
    for(i = STARTMULTITABLE; i <= ENDMULTITABLE; i++){
        int k;
        for(k = STARTMULTITABLE; k <= ENDMULTITABLE; k++){
            cout << i << "x" << k << "=" << (i*k) << endl;
        }
    }
    return 0;
}