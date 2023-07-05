#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    int N;

    cin >> N;
    cin >> str;

    int cnt = 0;
    char compChar = 'B';
    bool isCh = false;
    for (int i = 0; i < N; ++i) {
        if (str[i] == compChar) {
            isCh = true;
            continue;
        }
        while (i < N && str[i] != compChar) {
            i++;
        }
        cnt++;
    }

    if (isCh) cout << cnt + 1 << endl;
    else cout << cnt << endl;

    return 0;
}
