#include <iostream>
#include <string>
using namespace std;

string str;
int N;
int arr[1001];

// first : B

int main() {
    cin >> N;
    cin >> str;

    for (int i = 0; i < 1001; ++i) {
        arr[i] = -1;
    }

    arr[0] = 0;
    for (int i = 1; i <= N; ++i) {
        int m = 2147483647;
        if (str[i] == 'B') {
            for (int j = i - 1; j >= 0; --j) {
                if (arr[j] >= 0 && str[j] == 'J') {
                    m = min(m, arr[j] + (j - i) * (j - i));
                }
            }
        }
        if (str[i] == 'O') {
            for (int j = i - 1; j >= 0; --j) {
                if (arr[j] >= 0 && str[j] == 'B') {
                    m = min(m, arr[j] + (j - i) * (j - i));
                }
            }
        }
        if (str[i] == 'J') {
            for (int j = i - 1; j >= 0; --j) {
                if (arr[j] >= 0 && str[j] == 'O') {
                    m = min(m, arr[j] + (j - i) * (j - i));
                }
            }
        }
        if (m != 2147483647)
            arr[i] = m;
    }

    cout << arr[N - 1] << "\n";

    return 0;
}