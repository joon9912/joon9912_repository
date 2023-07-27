#include <iostream>
#include <vector>
using namespace std;

int T, n;
int arr[10001];
int dp[10001][4];
vector<int> v;

// dp[i][1] : 맨 앞이 1로 시작하는 경우
// dp[i][2] : 맨 앞이 2로 시작하는 경우
// dp[i][3] : 맨 앞이 3으로 시작하는 경우

int main() {
    int m = 0;

    cin >> T;

    dp[1][1] = dp[2][1] = 1;
    dp[2][2] = dp[3][1] = 1;
    dp[3][2] = dp[3][3] = 1;

    for (int i = 0; i < T; ++i) {
        cin >> n;
        m = max(m, n);
        v.push_back(n);
    }

    for (int i = 4; i <= m; ++i) {
        dp[i][1] = 1;
        dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
        dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
    }

    for (auto e : v)
        cout << dp[e][1] + dp[e][2] + dp[e][3] << "\n";
    /*
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3; // 1 + 1 + 1 , 1 + 2 , 3
    arr[4] = 4;
    arr[5] = 5;
    for (int i = 6; i <= m; ++i) {
        arr[i] = arr[i - 3] + (arr[i - 2] - arr[i - 5]) + 1;
    }

    for (auto e : v)
        cout << arr[e] << endl;
    */
    return 0;
}
