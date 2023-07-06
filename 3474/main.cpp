#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    int N, cnt;

    cin >> T;

    cnt = 0;
    for (int i = 0; i < T; ++i) {
        cin >> N;
        for (int j = 5; j <= N; j = j * 5) {
            cnt += N / j;
        }
        cout << cnt << "\n";
        cnt = 0;
    }
    return 0;
}
