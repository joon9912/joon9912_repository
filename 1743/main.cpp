#include <iostream>
using namespace std;

int N, M, K;
int arr[101][101];
int visited[101][101];
int ans, sum;

void dfs(int x, int y) {
    if (arr[x][y] && !visited[x][y]
        && (x > 0 && x <= N && y > 0 && y <= M))
    {
        // cout << x << " " << y << endl;
        visited[x][y] = 1;
        sum++;

        dfs(x + 1, y);
        dfs(x , y + 1);
        dfs(x - 1, y);
        dfs(x, y - 1);
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

int main() {
    int x, y;

    cin >> N >> M >> K;

    for (int i = 0; i < K; ++i) {
        cin >> x >> y;
        arr[x][y] = 1;
    }

    best();

    return 0;
}
