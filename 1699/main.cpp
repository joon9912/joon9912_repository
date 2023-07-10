#include <iostream>
using namespace std;

int N;

int arr[100001];

int main() {
    cin >> N;

    arr[1] = 1;
    for (int i = 2; i <= N; ++i) {
        arr[i] = arr[1] + arr[i - 1];
        for (int j = 2; j * j <= i; ++j) {
            if (j * j == i) {
                arr[i] = 1;
                break;
            }
            arr[i] = min(arr[i], arr[i - j * j] + arr[j * j]);
        }
    }
    cout << arr[N] << endl;
    return 0;
}