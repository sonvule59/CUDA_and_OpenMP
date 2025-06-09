#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cstdlib>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <sstream>
#include <omp.h>

using namespace std;

class c_main
{
private:
    
public:
    c_main();
    void f_input();
};

c_main::c_main()
{

}

void c_main::f_input()
{
    int i, j;
    
    #pragma omp parallel for
    for ( i = 1; i <= 9; ++i ){
        for ( j = 1; j <= 9; ++j ){
            cout << i << "x" <<  j << "=" << i * j << endl;
        }
    }
}

int main(){
    c_main main01;
    main01.f_input();
    
    return 0;
}