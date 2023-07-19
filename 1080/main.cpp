#include <iostream>
#include <string>
using namespace std;

int N, M, cnt; // <= 50
int arr[51][51];
int brr[51][51];

bool isEqual() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (arr[i][j] != brr[i][j])
                return false;
        }
    }
    return true;
}

int main() {
    string num;
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        cin >> num;
        for (int j = 0; j < M; ++j)
            arr[i][j] = num[j] - '0';
    }

    for (int i = 0; i < N; ++i) {
        cin >> num;
        for (int j = 0; j < M; ++j)
            brr[i][j] = num[j] - '0';
    }

    for (int i = 0; i < N - 2; ++i) {
        for (int j = 0; j < M - 2; ++j) {
            if (arr[i][j] != brr[i][j]) {
                for (int k = 0; k < 3; ++k) {
                    for (int l = 0; l < 3; ++l)
                        arr[i + k][j + l] = !arr[i + k][j + l];
                }
                cnt++;
            }
        }
    }

    if (isEqual())
        cout << cnt << "\n";
    else
        cout << -1 << "\n";

    return 0;
}
