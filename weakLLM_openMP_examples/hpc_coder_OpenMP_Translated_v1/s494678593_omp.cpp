#include<iostream>
#include<omp.h>
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define REP(i,a,b) for(int i=(int)a;i<(int)b;++i)
using namespace std;
void solver(){
    REP(i,1,10){
        REP(j,1,10){
            cout<<i<<"x"<<j<<"="<<i*j<<endl;
        }
    }

}

int main() {
    #pragma omp parallel
    {
        solver();
    }
}