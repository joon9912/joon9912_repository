#include <iostream>
using namespace std;

int dp[1001];
int sum[1001];
int arr[1001];
int N;

int main() {
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];

        dp[i] = 1;
        sum[i] = arr[i];
    }

    for(int i = 1; i <= N; ++i) {
        for (int j = 1; j < i; ++j) {
            if (arr[j] < arr[i]
                && (sum[i] < sum[j] + arr[i]))
            {
                dp[i] = dp[j] + 1;
                sum[i] = sum[j] + arr[i];
            }
        }
    }

    int mySum = sum[1];
    for (int i = 1; i <= N; ++i) {
        mySum = max(mySum, sum[i]);
    }
    cout << mySum << "\n";

    /*
    cout << "dp\n";
    for (int i = 1; i <= N; ++i) {
        cout << dp[i] << " ";
    }
    cout << "\n";

    cout << "sum\n";
    for (int i = 1; i <= N; ++i) {
        cout << sum[i] << " ";
    }
    cout << "\n";
    */
    return 0;
}