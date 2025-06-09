#include <bits/stdc++.h>
#define INT(name) int name; scanf("%d",&name);
#define VINT(name,n) vector<int> name(n); for(int i = 0;i < n;i++) scanf("%d",&name[i]);
#define FOR(i,n) for(int i = 0;i < n;i++)

using namespace std;

int main(int argc, char const *argv[]){
	#pragma omp parallel for
	for(int i = 1;i <= 9;i++){
		for(int j = 1;j <= 9;j++){
			printf("%dx%d=%d\n",i,j,i*j);
		}
	}
	return 0;
}