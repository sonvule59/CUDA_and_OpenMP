#include<bits/stdc++.h>
#include<omp.h>

using namespace std;

int main()
{
    int hi,a=10;
    vector<int> mou;
    while(a--)
    {
        cin>>hi;
        mou.push_back(hi);
    }
    sort(mou.rbegin(),mou.rend());
    #pragma omp parallel for
    for(int i=0;i<3;i++)
        cout<<mou[i]<<endl;
    return 0;
}