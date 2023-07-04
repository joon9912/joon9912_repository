#include <iostream>
#include <string>
using namespace std;

int visited[20001];

int main() {
    string str;
    int N, K;

    cin >> N >> K;
    cin >> str;

    int sum = 0;
    for (int i = 0; i < N; ++i) {
        if (str[i] == 'H')
            continue;
        if (str[i] == 'P') {
            for (int j = max(0, i - K); j <= min(N - 1, i + K); ++j) {
                if (str[j] == 'H' && !visited[j]) {
                    sum++;
                    visited[j] = 1;
                    break;
                }
            }
        }
    }

    cout << sum << endl;

    return 0;
}
