#include <iostream>
#include <omp.h>

using namespace std;
int main()
{
    int i=1;
    #pragma omp parallel for
    while(i<10)
    {
        for(int a=1;a<10;a++)
        {    
            
        cout<<i<<"x"<<a<<"="<<i*a<<endl;
            
        }
    i=i+1;
    }
}