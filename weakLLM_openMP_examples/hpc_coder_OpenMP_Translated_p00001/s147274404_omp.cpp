#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    int h;
    int max1 = 0, max2 = 0, max3 = 0;
    #pragma omp parallel shared(max1, max2, max3)
    {
        #pragma omp for
        for (int i = 0; i < 10; i++)
        {
            cin >> h;
            #pragma omp critical
            {
                if (max1 <= h)
                {
                    max3 = max2; max2 = max1; max1 = h;
                }
                else if (max2 <= h)
                {
                    max3 = max2; max2 = h;
                }
                else if (max3 <= h)
                {
                    max3 = h;
                }
            }
        }
    }
    cout << max1 << endl;
    cout << max2 << endl;
    cout << max3 << endl;
    return 0;
}