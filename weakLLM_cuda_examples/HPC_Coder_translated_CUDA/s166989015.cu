#include <stdio.h>
#include <stdlib.h>

#define FOR(i,n) 		for(int(i)=0;(i)<(int)(n);(i)++)
#define FORN(i,a,b,c) 	for(int(i)=a;i<(int)(b);i+=(c))
#define RES(x,nilai)	memset(x,nilai,sizeof(x));
#define pb              push_back
#define mp              make_pair
#define INF				1000000000

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

inline string IS(int a){
    char x[100];
    sprintf(x,"%d",a); string s = x;
    return s;
}

inline int SI(string a){
    char x[100]; int res;
    strcpy(x,a.c_str()); sscanf(x,"%d",&res);
    return res;
}

//==============================================

bool cmp(int x,int y) {return x>y;}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("13.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	for(int i =1; i <=9;i++) {
        for(int j =1; j<=9;j++) {
printf("%d x %d = %d\n",i,j,i*j);
}
        }
		
    return 0;
}