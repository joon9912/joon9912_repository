#include <iostream>
using namespace std;

int n, k;
int coin[101];
int dp[101][10001];
// 앞 idx : 끝 숫자, 뒤 idx : 합

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> coin[i];
        dp[i][i] = 1;
    }

    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int l = 0; l < n; ++l)
                dp[coin[j]][i] += dp[coin[l]][i - coin[j]];
        }
    }

    /*for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= k; ++j)
            cout << dp[coin[i]][j] << " ";
        cout << endl;
    }*/

    long long sum = 0;
    for (int i = 0; i < n; ++i)
        sum += dp[coin[i]][k];
    cout << sum << endl;

    return 0;
}
