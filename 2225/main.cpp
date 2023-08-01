#include <iostream>
using namespace std;

int N, K;
long long arr[201][201];

int main() {
    cin >> N >> K;

    for (int i = 0; i <= N; ++i) {
        arr[i][1] = 1;
    }

    for (int i = 0; i <= N; ++i) {
        for (int j = 2; j <= K; ++j) {
            for (int k = 0; k <= i; ++k) {
                arr[i][j] = (arr[i][j] + arr[i - k][j - 1]) % 1000000000;
            }
        }
    }

    cout << arr[N][K] << endl;
    return 0;
}
