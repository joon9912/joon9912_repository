#include <iostream>
using namespace std;

int N;
// int arr[2][100001];
long long dp[2][100001];

void print_dp() {
    for (int i = 1; i <= N; ++i)
        cout << dp[0][i] << " ";
    cout << endl;

    for (int i = 1; i <= N; ++i)
        cout << dp[1][i] << " ";
    cout << endl;
}

int main() {
    cin >> N;

    dp[0][0] = 0;
    dp[1][0] = 0;

    dp[0][1] = 1;
    dp[1][1] = 1;

    for (int i = 2; i <= N; ++i) {
        dp[0][i] =
        dp[1][i] =
    }

    print_dp();

    long long sum = 0;
    for (int i = 1; i <= N; ++i) {
        sum += dp[0][i] + dp[1][i];
    }

    cout << sum << "\n";
    return 0;
}
