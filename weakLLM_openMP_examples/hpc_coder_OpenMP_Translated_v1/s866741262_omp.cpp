#include <iostream>
#include <omp.h>
using namespace std;

void outerLoop(int i);
void innerLoop(int i, int j);

static const int MAX = 9;

int main()
{
    #pragma omp parallel
    {
        outerLoop(1);
    }
}

void outerLoop(int i)
{
    if (MAX < i) {
        return;
    }
    #pragma omp parallel for
    for (int j = 1; j <= MAX; j++) {
        innerLoop(i, j);
    }
    outerLoop(i + 1);
}

void innerLoop(int i, int j)
{
    if (MAX < j) {
        return;
    }
    cout << i << "x" << j << "=" << i * j << endl;;
    innerLoop(i, j + 1);
}