#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v;
    int N, c;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> c;
        v.push_back(c);
    }

    sort(v.begin(), v.end(), greater<>());


    int sum = 0;
    for (int i = 0; i < v.size(); i ++) {
        if (i % 3 == 2) continue;
        sum += v[i];
    }

    cout << sum << endl;
    return 0;
}