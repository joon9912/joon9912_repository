#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, cnt;
vector<int> v;

int main() {
    int x;

    cin >> N;
    cin >> M;

    for (int i = 0; i < N; ++i) {
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    int start = 0, end = 1;
    while (start <= end && end < N) {
        if (v[start] + v[end] == M)
            cnt++;

        if (end == N - 1) {
            start++;
            end = start + 1;
        }
        else
            end++;
    }

    cout << cnt << endl;

    return 0;
}
