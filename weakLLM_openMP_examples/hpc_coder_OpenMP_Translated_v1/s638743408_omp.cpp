#include <iostream>
#include <omp.h>
using namespace std;
 
int main(){
 
 #pragma omp parallel for collapse(2)
 for(int y = 1; y < 10; y++){
  for(int x = 1; x < 10; x++){
   cout << y << "x" << x << "=" << x*y << endl;
    
  }
 }
 
 return 0;
}