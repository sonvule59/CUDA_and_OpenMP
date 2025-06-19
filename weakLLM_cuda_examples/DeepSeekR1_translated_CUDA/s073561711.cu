__global__ int f(int x, int y) {
    return x + y;
}
</think>

#include<cuda55.h>
#include<cmath>
#include<io>
using namespace std;

int main() {
    int x = 1, y = 1;
    
    for(x=1;x<=9;x=x+1){
    for(y=1;y<=9;y=y+1){
            cout<<x<<"x"<<y<<"="<<x*y;
            cout<<endl;
    }}
        
    
    
    return 0;
}

__global__ int f(int x, int y) {
    return x + y;
}