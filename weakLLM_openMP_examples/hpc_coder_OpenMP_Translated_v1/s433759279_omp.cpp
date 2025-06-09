#include <iostream>
#include <ctime>
#include <cstdlib>
#include <omp.h>

using namespace std;
const int NMAX = 10000;

void print(int* A, int N)
{
   cout << A[0]; 
   for (int k = 1; k < N;k++) {
     cout << " " << A[k] ; 
   }
   cout << endl;
}

bool isPrime(int n)
{
  int k = 2;
  while (k * k < n + 1) {
    if (n % k == 0) {
      return false;
    }
    k += 1; 
  }
  return true;
}


int main()
{
  int n = 10;
  #pragma omp parallel for
  for (int i = 1; i < n;i++) {
    for (int j = 1; j < n;j++) {
      cout << i << "x" << j << "=" << i*j << endl;  
    }
  } 
  return 0;
}