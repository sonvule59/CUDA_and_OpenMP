#include<iostream>

using namespace std;

__global__ void print_table(int y, int i){
    printf("%d x %d = %d\n", y, i, y*i);
}

int main(){
    int y,i;
    for(y = 1;y < 10;y++){
          for(i = 1;i < 10;i++){
          print_table<<<1,1>>>(y,i);
          }
    }
}