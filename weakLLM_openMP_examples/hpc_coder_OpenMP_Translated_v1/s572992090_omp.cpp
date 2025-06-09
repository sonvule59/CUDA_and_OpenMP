#include <iostream>
#include<math.h>
#include<iomanip>
#include<omp.h>
using namespace std;

int main()
{
    int  i=0,j=0;

    #pragma omp parallel for
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            cout << i+1 << 'x' << j+1 << '=' << (i+1)*(j+1) << endl;

        }
    }


    /*for(i=0;i<m;i++){//????????¨??????
        for(j=0;j<l;j++){
           cout << bb[i][j] << ' ';

        }
        cout << endl;
    }*/





    //cout << endl;

return 0;

}