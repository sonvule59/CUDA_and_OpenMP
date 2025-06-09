#include <iostream>
#include <omp.h>
using namespace std;

int main(){

 int first_num;
 int second_num;

 #pragma omp parallel for private(first_num, second_num)
 for(first_num = 1 ; first_num <= 9 ; first_num++){
   for(second_num = 1 ; second_num <= 9 ; second_num++){
     cout << first_num << "x" << second_num << "=" << first_num * second_num << endl;
   }
 }
 return 0;
}