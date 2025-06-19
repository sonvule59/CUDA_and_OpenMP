#include <iostream>

using namespace std;

int main() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            int n1 = i + 1;
            int n2 = j + 1;
            cout << to_string(n1) + "x" + to_string(n2) + "=" + to_string(n1 * n2) << endl;
        }
    }
    return 0;
}