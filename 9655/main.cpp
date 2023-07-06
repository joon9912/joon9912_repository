#include <iostream>
using namespace std;

int N;
int dp[1001];

int main() {
    // SK, CY
    cin >> N;

    dp[1] = 1; // SK odd  #
    dp[2] = 2; // CY even #
    dp[3] = 1; // SK

    for (int i = 4; i <= N; ++i)
        dp[i] = min(dp[i - 3] + 1, dp[i - 1] + 1);

    if (dp[N] % 2 == 1)
        cout << "SK\n";
    else
        cout << "CY\n";

    return 0;
}
