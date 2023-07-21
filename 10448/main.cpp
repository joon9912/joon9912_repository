#include <iostream>
using namespace std;

int test (int num) {
    for (int i = 1; i <= 45; ++i) {
        for (int j = i; j <= 45; ++j) {
            for (int k = j; k <= 45; ++k) {
                if ((i * (i + 1) + j * (j + 1) + k * (k + 1)) / 2 == num)
                    return 1;
            }
        }
    }
    return 0;
}

int main() {
    int n, k;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> k;

        cout << test(k) << endl;
    }

    return 0;
}
