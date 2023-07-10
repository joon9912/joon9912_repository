#include <iostream>
using namespace std;

int A, B, C, x, y;
int arr[101];

int main() {
    cin >> A >> B >> C;

    for (int i = 0; i < 3; ++i) {
        cin >> x >> y;

        for (int j = x; j < y; ++j)
            arr[j]++;
    }

    int sum = 0;
    for (int i = 1; i <= 100; ++i) {
        if (arr[i] == 1)
            sum += A;
        if (arr[i] == 2)
            sum += B * 2;
        if (arr[i] == 3)
            sum += C * 3;
    }
    cout << sum << "\n";
    return 0;
}
