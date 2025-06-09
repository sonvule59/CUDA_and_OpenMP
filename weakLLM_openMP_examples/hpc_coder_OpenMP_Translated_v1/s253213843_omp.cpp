#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
  int a,b;
  #pragma omp parallel for private(a,b)
  for(a=1;a<10;a++){
    for(b=1;b<10;b++){
        if(a==9&&b==10)
            break;
            else{
                cout<<a<<"x"<<b<<"="<<a*b<<endl;
            }

    }
  }
 return 0;
}