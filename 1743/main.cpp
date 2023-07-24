#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int N, M, K;
int arr[101][101];
int visited[101][101];
int dx[]{-1,0,1,0};
int dy[]{0,1,0,-1};

int ans, sum;
queue<pair<int, int>> q;

void dfs(int x, int y) {
    if (arr[x][y] && !visited[x][y]
        && (x > 0 && x <= N && y > 0 && y <= M))
    {
        // cout << x << " " << y << endl;
        visited[x][y] = 1;
        sum++;

        for (int i = 0; i < 4; ++i) {
            dfs(x + dx[i], y + dy[i]);
        }
    }
    ans = max(ans, sum);
}

void bfs(int m, int n) {
    // cout << m << " " << n << endl;
    q.push(make_pair(m, n));
    visited[m][n] = 1;
    sum++;
    while (!q.empty()) {
        auto x = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x.first + dx[i];
            int ny = x.second + dy[i];

            if (arr[nx][ny] && !visited[nx][ny]
                && nx > 0 && nx <= N && ny > 0 && ny <= M)
            {
                visited[nx][ny] = 1;
                q.push(make_pair(nx, ny));
                sum++;
            }
        }
    }
    ans = max(ans, sum);
}

void best() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            dfs(i, j);
            sum = 0;
        }
    }

    cout << ans << endl;
}

void best2() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (arr[i][j] && !visited[i][j]) {
                bfs(i, j);
                sum = 0;
            }
        }
    }

    cout << ans << endl;
}

int main() {
    int x, y;

    cin >> N >> M >> K;

    for (int i = 0; i < K; ++i) {
        cin >> x >> y;
        arr[x][y] = 1;
    }

    // best();
    best2();

    return 0;
}
