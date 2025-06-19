#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(r) (r).begin(),(r).end()
#define vmax_v(ary) *max_element(all(ary))
#define vmin_v(ary) *min_element(all(ary))
#define vmax_id(ary) distance((ary).begin(),max_element(all(ary)))
#define vmin_id(ary) distance((ary).begin(),min_element(all(ary)))

using ll = int64_t;
using pll = pair<ll,ll>;
using vl = vector<ll>;

const ll INF=INT64_MAX;
const double EPS=1e-10;
const double PI=acos(-1.0);

void init(){cin.tie(0);ios::sync_with_stdio(false);}
//----------------------------------------------------

__global__ void kernel(int* arr){
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if(idx < 100){
        arr[idx] = idx;
    }
}

int main(){
    init();

    int* arr;
    cudaMallocManaged(&arr, 100 * sizeof(int));

    kernel<<<1,100>>>(arr);

    for(int i=0;i<100;i++){
        cout << arr[i] << endl;
    }

    cudaFree(arr);

    return 0;
}