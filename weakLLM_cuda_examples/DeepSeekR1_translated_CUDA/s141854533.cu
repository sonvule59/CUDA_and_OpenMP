__global__ sum = i * j;
cout << i << "x" << j << "=" << sum << endl;
__global__ sum = i * j;
cout << i << "x" << j << "=" << sum << endl;
</think>

#include<cuda.h>
#include<iostream>
using namespace std;

__global__ void my_function() {
    int i = __local__(int) i;
    int j = __local__(int) j;
    int sum = i * j;
    cout << i << "x" << j << "=" << sum << endl;
}

int main() {
    int sum;
    
    for(int i=1; i<10; i++){
        for(int j=1; j<10; j++){
            sum = i * j;
            cout << i << "x" << j << "=" << sum << endl;
        }
    }

    return 0;
}