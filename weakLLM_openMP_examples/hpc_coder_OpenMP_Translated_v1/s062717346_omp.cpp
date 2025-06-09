#include<bits/stdc++.h>
#include<omp.h>
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define rep1(i,a,b) for(int i=a;i<=(b);++i)
#define per(i,a,b) for(int i=a;i>(b);--i)
#define per1(i,a,b) for(int i=a;i>=(b);--i)
#define LL long long
#define inf 0x7f7f7f7f
#define N 35
using namespace std;

int main()
{
	int a=1,b=1;
	while(a<10&&b<10)
	{
		#pragma omp parallel
		{
			#pragma omp single
			{
				printf("%dx%d=%d\n",a,b,a*b);
			}
			b++;
			if(b>9)
			{
				a++;
				b=1;
			}
		}
	}
}