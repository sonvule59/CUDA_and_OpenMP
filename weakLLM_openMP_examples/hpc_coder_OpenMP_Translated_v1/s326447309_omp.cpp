#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>
#include <omp.h>
using namespace std;
#define rep(I,N) for(int I = 0; I < (int)(N); I++)
#define FIN(V) cout<<V<<endl
#define pb push_back
#define INF (1 << 30)
typedef pair<int, int> P;
typedef long long ll;
typedef priority_queue<int> pq;

int main(void){
	rep(i, 9){
		rep(j, 9){
			cout << i+1 << "x" << j+1 << "=" << (i+1)*(j+1) << endl;
		}
	}
	return 0;	
}

The OpenMP version uses the #pragma omp parallel for directive to parallelize the outer loop. The loop is now executed in parallel by multiple threads. The inner loop is not parallelized, as it is not necessary for the problem.