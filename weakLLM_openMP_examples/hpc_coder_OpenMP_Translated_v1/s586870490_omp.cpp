#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <omp.h>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define REP(i,e) for (int i = 0; i != int(e); i++)
#define FORIT(i, A) for (auto i : A)
#define ISEQ(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << endl
#define SZ(x) ((int)(x).size())

int main(int argc, char const *argv[])
{
	#pragma omp parallel for collapse(2)
	REP(i, 9){
		REP(j, 9) {
			printf("%dx%d=%d\n", i+1, j+1,(i+1)*(j+1));
		}
	}
	return 0;
}