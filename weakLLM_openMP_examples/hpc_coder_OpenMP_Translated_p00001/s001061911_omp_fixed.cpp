#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    const int len = 10;
    int arr[len];

    for (int i = 0; i < len; i++)
        cin >> arr[i];

    bool swapped;
    for (int i = 0; i < len - 1; i++) {
        swapped = false;
        #pragma omp parallel for
        for (int j = 0; j < len - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                #pragma omp critical
                {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
        }
        if (!swapped) break;
    }

    cout << "Sorted numbers:" << endl;
    for (int i = 0; i < len; i++)
        cout << arr[i] << endl;

    return 0;
}