#include<iostream>
 
using namespace std;
__global__ void a(string s[11]){
	return ;
}
int main(){
	string s[4];
	a<<<1,1>>>(s);
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            cout<<i<<"x"<<j<<"="<<i*j<<endl;
        }
    }
    return 0;
}