#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
  int m,n;
  
  m=1;
  n=1;

  #pragma omp parallel for
  while(true){
    if(n==10){
      m=m+1;
      n=1;
    }
    if(m==10) break;
    
    cout << m << 'x' << n << "=" << m*n << endl;
    n++;

  }
  return 0;
}