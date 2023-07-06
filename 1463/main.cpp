#include <iostream>
using namespace std;

// if (X % 3 == 0) X = X / 3;
// if (X % 2 == 0) X = X / 2;
// X = X - 1;

int dp[1000001];

int main() {
    int N;
    cin >> N;

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i <= N; ++i) {
        if (i % 3 == 0 && i % 2 == 0) {
            int minimum = dp[i / 3] + 1;
            dp[i] = minimum;

            if (minimum > dp[i / 2] + 1) {
                dp[i] = dp[i / 2] + 1;
                minimum = dp[i / 2] + 1;
            }
            if (minimum > dp[i / 3] + 1)
                dp[i] = dp[i / 3] + 1;
        }
        else if (i % 3 == 0)
            dp[i] = min(dp[i / 3] + 1, dp[i - 1] + 1);
        else if (i % 2 == 0)
            dp[i] = min(dp[i / 2] + 1, dp[i - 1] + 1);
        else
            dp[i] = dp[i - 1] + 1;
    }

    cout << dp[N] << endl;

    return 0;
}
