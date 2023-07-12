#include <iostream>
#include <queue>
using namespace std;

int N, M, V, x, y;
int arr[1001][1001];
int visited[1001];
queue<int> q;

void dfs(int x) {
    cout << x << " ";
    visited[x] = 1;
    for (int i = 1; i <= N; ++i) {
        if (arr[x][i] && !visited[i])
            dfs(i);
    }
}

void bfs(int x) {
    q.push(x);
    visited[x] = 1;
    cout << x << " ";
    while (!q.empty()) {
        int top = q.front();
        q.pop();

        for (int i = 1; i <= N; ++i) {
            if (arr[top][i] && !visited[i]) {
                cout << i << " ";
                q.push(i);
                visited[i] = visited[top] + 1; // visited #
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> V;

    for (int i = 0; i < M; ++i) {
        cin >> x >> y;

        arr[x][y] = 1;
        arr[y][x] = 1;
    }

    dfs(V); cout << "\n";

    for (int i = 1; i <= N; ++i)
        visited[i] = 0;

    bfs(V); cout << "\n";

    /*for (int i = 1; i <= N; ++i) {
        cout << i << " : " << visited[i] << "\n";
    }
    */
    return 0;
}
