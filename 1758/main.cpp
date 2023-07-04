#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v;
    int N, t;
    long long sum;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> t;
        v.push_back(t);
    }

    sort(v.begin(), v.end(), greater<>());

    sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        sum += max(v[i] - i, 0);
    }

    cout << sum << endl;

    return 0;
}
