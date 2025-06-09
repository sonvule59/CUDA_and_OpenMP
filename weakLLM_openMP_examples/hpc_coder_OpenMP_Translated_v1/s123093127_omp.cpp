#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <omp.h>
using namespace std;
static const double EPS = 1e-5;
typedef long long ll;
#define FOR(i,n) for(i=0;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
	rep(i,9){
		rep(j,9){
			printf("%dx%d=%d\n",i+1,j+1,(i+1)*(j+1));
		}
	}
	#pragma omp parallel for
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			printf("%dx%d=%d\n",i+1,j+1,(i+1)*(j+1));
		}
	}
	return 0;
}