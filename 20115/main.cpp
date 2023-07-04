#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v;
    int N;
    cin >> N;

    int x;
    for (int i = 0; i < N; ++i) {
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    long double sum = 0;
    for (int i = 0; i < N - 1; ++i) {
        double j = v[i] / 2.0;
        sum += j;
    }
    sum += v[N - 1];

    cout << sum << endl;
    return 0;
}
