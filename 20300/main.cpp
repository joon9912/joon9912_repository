#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<long long> v;
    int N;
    long long M, t;

    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> t;
        v.push_back(t);
    }

    sort(v.begin(), v.end());

    if (N % 2 == 0) {
        M = 0;
        for (int i = 0; i < N / 2; ++i)
            M = max(M, v[i] + v[N - i - 1]);
    }
    if (N % 2 == 1) {
        M = v[N - 1];
        for (int i = 0; i < N / 2; ++i)
            M = max(M, v[i] + v[N - i - 2]);
    }

    cout << M << endl;

    return 0;
}