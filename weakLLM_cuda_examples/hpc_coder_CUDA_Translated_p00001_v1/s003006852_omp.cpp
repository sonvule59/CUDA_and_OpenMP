c++
#include <iostream>
#include <queue>

using namespace std;

__global__ void kernel(priority_queue<int> pq) {
    int idx = threadIdx.x + blockIdx.x * blockDim.x;
    if (idx < pq.size()) {
        std::cout << pq.top() << endl;
        pq.pop();
    }
}

int main() {
    priority_queue<int> pq;

    for (int i = 0; i < 10; ++i) {
        int height;
        cin >> height;
        pq.emplace(height);
    }

    int blockSize = 256;
    int numBlocks = (pq.size() + blockSize - 1) / blockSize;

    kernel<<<numBlocks, blockSize>>>(pq);

    cudaDeviceSynchronize();

    return 0;
}