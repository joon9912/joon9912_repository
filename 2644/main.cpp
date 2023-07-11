#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<int> q;
int arr[101][101];
int visited[101];

int main() {
    int n, x, y, m, a, b;

    cin >> n;
    cin >> a >> b;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }

    // root is a
    q.push(a);
    int top = -1;
    while (!q.empty()) {
        top = q.front();
        q.pop();
        for (int i = 1; i <= n; ++i) {
            if (arr[top][i] != 0 && !visited[i]) {
                q.push(i);
                visited[i] = visited[top] + 1;
            }
        }
    }

    if (visited[b] == 0)
        cout << -1 << "\n";
    else
        cout << visited[b] << "\n";

    return 0;
}
