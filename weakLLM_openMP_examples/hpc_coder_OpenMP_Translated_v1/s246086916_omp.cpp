#include <algorithm>
#include <climits>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map> //pair is also included in this library
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <omp.h>

#define REP(i, s, n) for(int i = (int)(s); i < (int)(n); i++)

using namespace std;

typedef long long int ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PII;

//prefer define statement
//for reason that const int ver. of INF will raise a silly warning (unused variable)
#define INF (INT_MAX/3)
#define LIM_INF (INT_MAX)
//const int INF = INT_MAX/3;

/*------------------------------------------------------------------------------*/

int main(){
  REP(i, 1, 10){
    REP(j, 1, 10){
      cout << i << "x" << j << "=" << i*j << endl;
    }
  }

  #pragma omp parallel for
  REP(i, 1, 10){
    REP(j, 1, 10){
      cout << i << "x" << j << "=" << i*j << endl;
    }
  }

  return 0;
}

The OpenMP version uses the #pragma omp parallel for directive to parallelize the outer loop. This directive tells the compiler to create a team of threads and distribute the iterations of the loop among them. The inner loop is not parallelized, as it is not necessary for the problem at hand.