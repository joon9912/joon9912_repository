#include <iostream>
using namespace std;

int N, num; // 2 <= N <= 11
int arr[12];
char dop[4]{'+', '-', '*', '/'};
char op[12];
int visited[12];
// int numOfOP[4]; // + - * /
int ans_min = 1000000000, ans_max = -1000000000;

void calc(int loc, int sum, int level) {
    if (op[loc] == '+')
        sum += arr[++level];
    if (op[loc] == '-')
        sum -= arr[++level];
    if (op[loc] == '*')
        sum *= arr[++level];
    if (op[loc] == '/')
        sum /= arr[++level];

    if (level == N - 1) {
        ans_min = min(ans_min, sum);
        ans_max = max(ans_max, sum);
        return;
    }
    for (int i = 0; i < N - 1; ++i) {
        if (!visited[i]) {
            visited[i] = 1;
            calc(i, sum, level);
            visited[i] = 0;
        }
    }
}

void recur() {
    for (int i = 0; i < N - 1; ++i) {
        visited[i] = 1;
        calc(i, arr[0], 0); // loc, sum
        visited[i] = 0;
    }

}

int main() {
    cin >> N;

    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    int idx = 0;
    for (int i = 0; i < 4; ++i) {
        cin >> num;

        for (int j = 0; j < num; ++j) {
            op[idx++] = dop[i];
        }
    }

    recur();

    cout << ans_max << "\n" << ans_min << "\n";
    return 0;
}
