#include<iostream>
#include<omp.h>
 
using namespace std;
void a(string s[11]){
	return ;
}
int main(){
	string s[4];
	a(s);
    #pragma omp parallel for
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            cout<<i<<"x"<<j<<"="<<i*j<<endl;
        }
    }
    return 0;
}