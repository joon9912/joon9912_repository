#include <iostream>
#include <vector>
using namespace std;

int n, T;
vector<long long> v[4];
vector<int> vv;

int main() {
    cin >> T;

    int m = 0;
    for (int i = 0; i < T; ++i) {
        cin >> n;
        m = max(m, n);
        vv.push_back(n);
    }

    v[1].push_back(0);
    v[2].push_back(0);
    v[3].push_back(0);

    v[1].push_back(1); // v[1][1]
    v[2].push_back(0); // v[2][1]
    v[3].push_back(0); // v[3][1]

    v[1].push_back(1); // v[1][2]
    v[2].push_back(1); // v[2][2]
    v[3].push_back(0); // v[3][2]

    v[1].push_back(2); // v[1][3]
    v[2].push_back(1); // v[2][3]
    v[3].push_back(1); // v[3][3]

    for (int i = 4; i <= m; ++i) {
        long long sum = 0;
        for (int j = 1; j <= 3; ++j) {
            sum = (v[1][i - j] + v[2][i - j] + v[3][i - j]) % 1000000009;
            v[j].push_back(sum);
        }
    }

    for (auto e : vv) {
        cout << (v[1][e] + v[2][e] + v[3][e]) % 1000000009 << "\n";
    }
    return 0;
}
