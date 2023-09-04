#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, V;
vector<int> v[1001];
int visited[1001];

void clear_visited() {
    for (int i = 0; i <= 1000; ++i)
        visited[i] = 0;
}

void dfs(int x) {
    cout << x << " ";
    visited[x] = 1;

    for (auto e : v[x]) {
        if (!visited[e]) {
            visited[e] = 1;
            dfs(e);
        }
    }
}

void bfs(int x) {
    queue<int> q;

    q.push(x);
    visited[x] = 1;
    while (!q.empty()) {
        int a = q.front();
        q.pop();

        cout << a << " ";

        for (auto e : v[a]) {
            if (!visited[e]) {
                q.push(e);
                visited[e] = 1;
            }
        }
    }
}

int main() {
    cin >> N >> M >> V;

    int x, y;
    for (int i = 0; i < M; ++i) {
        cin >> x >> y;

        v[x].push_back(y);
        v[y].push_back(x);
    }

    for (int i = 1; i <= N; ++i) {
        sort(v[i].begin(), v[i].end());
    }

    dfs(V);
    cout << "\n";

    clear_visited();

    bfs(V);
    cout << "\n";

    return 0;
}