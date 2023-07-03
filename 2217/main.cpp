#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main() {
    int N, max;

    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    max = 0;
    for (int i = 0; i < N; ++i) {
        int sum = (N - i) * arr[i];

        if (sum > max)
            max = sum;
    }

    cout << max << endl;

    return 0;
}
