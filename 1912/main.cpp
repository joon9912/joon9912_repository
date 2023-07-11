#include <iostream>
using namespace std;

int n, x;
int arr[100001];
int sum[100001];

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sum[i] = arr[i];
    }

    for (int i = 1; i < n; ++i) {
        sum[i] = max(sum[i], sum[i - 1] + arr[i]);
    }

    int max = sum[0];
    for (int i = 0; i < n; ++i) {
        if (max < sum[i])
            max = sum[i];
    }
    cout << max << "\n";
    /*
    for (int i = 0; i < n; ++i)
        cout << sum[i] << " ";
    cout << endl;
    */
    return 0;
}
