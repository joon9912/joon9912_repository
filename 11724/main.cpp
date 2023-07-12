#include <iostream>
using namespace std;

int N, M, u, v;
int arr[1001][1001];
int visited[1001];

void dfs(int x) {
    visited[x] = 1;
    for (int i = 1; i <= N; ++i) {
        if (!visited[i] && arr[x][i])
            dfs(i);
    }
}

int main() {
    int res = 0;
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        cin >> u >> v;

        arr[u][v] = arr[v][u] = 1;
    }

    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            dfs(i);
            res++;
        }
    }

    cout << res << endl;

    return 0;
}
