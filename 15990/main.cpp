#include <iostream>
#include <vector>
using namespace std;

int T, n;
long long arr[4][100001]; // i: i(1,2,3)으로 시작, j: 수
vector<int> v;

int main() {
    cin >> T;

    int m = 0;
    for (int i = 0; i < T; ++i) {
        cin >> n;
        m = max(m, n);
        v.push_back(n);
    }

    arr[1][1] = 1;
    arr[2][1] = 0;
    arr[3][1] = 0;

    arr[1][2] = 0; // 1 + 1 xx
    arr[2][2] = 1;
    arr[3][2] = 0;

    arr[1][3] = 1; // 1 + 2
    arr[2][3] = 1; // 2 + 1
    arr[3][3] = 1; // 3

    for (int i = 4; i <= m; ++i) {
        arr[1][i] = (arr[2][i - 1] + arr[3][i - 1]) % 1000000009;
        arr[2][i] = (arr[1][i - 2] + arr[3][i - 2]) % 1000000009;
        arr[3][i] = (arr[1][i - 3] + arr[2][i - 3]) % 1000000009;
    }

    for (auto e : v) {
        cout << (arr[1][e] + arr[2][e] + arr[3][e]) % 1000000009 << "\n";
    }
    return 0;
}
