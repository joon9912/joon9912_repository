#include <iostream>
#include <vector>
using namespace std;

int N;
int arr[1001];
int dp[1001];
vector<int> v[1001];

int main() {
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        dp[i] = 1;
        v[i].push_back(arr[i]);
    }


    for (int i = 1; i < N; ++i) {
        int j = i;
        int size = 0;
        int idx = -1;
        for (; j >= 0; --j) {
            if (arr[i] > arr[j] && size < v[j].size()) {
                size = v[j].size();
                idx = j;
            }
        }
        if (idx == -1) continue;
        dp[i] = dp[idx] + 1;
        v[i].clear();
        for (auto e : v[idx])
            v[i].push_back(e);
        v[i].push_back(arr[i]);
    }

    int m = dp[0];
    int idx = 0;
    for (int i = 0; i < N; ++i) {
        if (m < dp[i]) {
            m = dp[i];
            idx = i;
        }
    }

    cout << dp[idx] << endl;
    for (auto e : v[idx]) {
        cout << e << " ";
    }
    return 0;
}
