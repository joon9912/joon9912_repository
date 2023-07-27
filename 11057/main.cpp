#include <iostream>
#include <string>
using namespace std;

#define UP_MAX 10007

int N;
long long arr[10][10001]; // 0 ~ 9으로 끝나는 수의 개수

int main() {
    // N은 자릿수
    cin >> N;

    for (int i = 0; i < 10; ++i) {
        arr[i][1] = 1;
        arr[i][2] = i + 1;
    }

    // i는 자릿 수
    for (int i = 3; i <= N; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k <= j; ++k)
                arr[j][i] = (arr[j][i] + arr[k][i - 1]) % 10007;
        }
    }

    long long sum = 0;
    for (int i = 0; i < 10; ++i)
        sum = (sum + arr[i][N]) % 10007;
    cout << sum << endl;

    return 0;
}