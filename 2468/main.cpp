#include <iostream>
using namespace std;

int N, safe, ans;
int arr[101][101];
int visited[101][101];
int dx[] {-1,0,1,0};
int dy[] {0,1,0,-1};

void dfs(int x, int y, int h) {
    visited[x][y] = 1;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (arr[nx][ny] > h && !visited[nx][ny]) {
            dfs(nx, ny, h);
        }
    }
}

void clear_visited() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            visited[i][j] = 0;
    }
}

void start(int h) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (arr[i][j] > h && !visited[i][j]) {
                dfs(i, j, h);
                safe++;
            }
        }
    }
    clear_visited();
    ans = max(ans, safe);
    safe = 0;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cin >> arr[i][j];
    }

    for (int i = 0; i <= 100; ++i) {
        start(i);
    }

    cout << ans << endl;
    return 0;
}
