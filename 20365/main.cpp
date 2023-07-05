#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    int N, cnt;
    char c1, c2;
    cin >> N;
    cin >> str;

    if (str[0] == 'R') {
        c1 = 'R';
        c2 = 'B';
    }
    if (str[0] == 'B') {
        c1 = 'B';
        c2 = 'R';
    }

    cnt = 1;
    for (int i = 0; i < N; ++i) {
        while (i < N && str[i] == c1) {
            i++;
        }
        if (i == N) break;

        while (i < N && str[i] == c2) {
            i++;
        }
        cnt++;
        if (i == N) break;
    }

    cout << cnt << endl;

    return 0;
}