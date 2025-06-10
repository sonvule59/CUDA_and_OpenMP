#include <iostream>
#include <queue>
#include <omp.h>

using namespace std;

int main() {
    priority_queue<int> pq;

    #pragma omp parallel for
    for (int i = 0; i < 10; ++i) {
        int height;
        cin >> height;
        pq.emplace(height);
    }

    #pragma omp parallel for
    for (int i = 0; i <= 2; ++i) {
        std::cout << pq.top() << endl;
        pq.pop();
    }

    return 0;
}