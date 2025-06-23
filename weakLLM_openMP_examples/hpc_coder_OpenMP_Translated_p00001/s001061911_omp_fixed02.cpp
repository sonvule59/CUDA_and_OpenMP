#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    const int len = 10;
    int arr[len];

    for (int i = 0; i < len; i++)
        cin >> arr[i];

    bool sorted = false;
    while (!sorted) {
        sorted = true;
        #pragma omp parallel for
        for (int i = 0; i < len - 1; i += 2) {
            if (arr[i] > arr[i + 1]) {
                #pragma omp critical
                {
                    swap(arr[i], arr[i + 1]);
                    sorted = false;
                }
            }
        }
        #pragma omp parallel for
        for (int i = 1; i < len - 1; i += 2) {
            if (arr[i] > arr[i + 1]) {
                #pragma omp critical
                {
                    swap(arr[i], arr[i + 1]);
                    sorted = false;
                }
            }
        }
    }

    cout << "Sorted numbers:" << endl;
    for (int i = 0; i < len; i++)
        cout << arr[i] << endl;

    return 0;
}