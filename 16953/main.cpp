#include <iostream>
#include <queue>
#include <utility>
using namespace std;

queue<pair<long long, int>> q;
int ans;

void bfs(int A, int B) {
    q.push(make_pair(A, 1));
    while (!q.empty()) {
        long long x = q.front().first;
        int level = q.front().second;
        q.pop();

        long long y = 2 * x;
        long long z = 10 * x + 1;

        if (y == B || z == B) {
            ans = level + 1;
            return;
        }
        if (y < B) q.push(make_pair(y, level + 1));
        if (z < B) q.push(make_pair(z, level + 1));
    }
}

int main() {
    int A, B;

    cin >> A >> B;

    bfs(A, B);

    if (ans)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}
