#include<iostream>
#include<omp.h>
using namespace std;
class solve{ 
    public:
        void qq(){ 
            #pragma omp parallel for
            for(int i=1;i<10;i++){ 
                for(int j=1;j<10;j++){ 
                    cout<<i<<"x"<<j<<"="<<i*j<<endl;
                }
            }
        }
};
int main(){
    solve ans;
    ans.qq();
    return 0;
}