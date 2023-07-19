#include <iostream>
using namespace std;

int N;
int L[21];
int J[21];
int dp[21][101]; // ith j health joy

int main() {
    int health;
    int joy;
    int max_joy = 0;

    cin >> N;

    // lose life
    for (int i = 1; i <= N; ++i) {
        cin >> L[i];
    }

    // add joy
    for (int i = 1; i <= N; ++i) {
        cin >> J[i];
    }

    int maximum = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 100; j >= 0; --j) {
            if (j - L[i] > 0) // 0 < health <= 100
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - L[i]] + J[i]);
            else // health < 0
                dp[i][j] = dp[i - 1][j];
            maximum = max(maximum, dp[i][j]);
        }
    }

    cout << maximum << "\n";

    return 0;
}
