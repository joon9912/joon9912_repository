#include <iostream>
using namespace std;

int N;
long long dp[91];

int main() {
    cin >> N;

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 3;

    for (int i = 5; i <= N; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[N] << endl;

    return 0;
}