#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K;
int arr[101][101];
int visited[101][101];
int dx[] { -1,0,1,0 };
int dy[] { 0,1,0,-1 };
queue<pair<int, int>> q;
vector<int> area;
int ans;

void bfs() {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!visited[i][j] && arr[i][j] == 0) {
                //cout << i << " " << j << "\n";
                int sum = 1;
                ans++;
                q.push(make_pair(i, j));
                visited[i][j] = 1;
                while (!q.empty()) {
                   int x = q.front().first;
                   int y = q.front().second;
                   q.pop();

                   for (int k = 0; k < 4; ++k) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (arr[nx][ny] == 0 && !visited[nx][ny]
                            && nx >= 0 && nx < M
                            && ny >= 0 && ny < N)
                        {
                            visited[nx][ny] = 1;
                            q.push(make_pair(nx, ny));
                            sum++;
                            //cout << nx << " " << ny << endl;
                        }
                   }
                }
                area.push_back(sum);
                //cout << endl;
            }
        }
    }
}

void print_arr() {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int x1, x2, y1, y2;

    cin >> M >> N >> K;

    for (int i = 0; i < K; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;

        for (int a = x1; a < x2; ++a)
            for (int b = y1; b < y2; ++b)
                arr[b][a] = 1;
    }

    // print_arr();

    bfs();

    sort(area.begin(), area.end());

    cout << ans << endl;
    for (auto e : area)
        cout << e << " ";
    cout << endl;

    /*
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    */

    return 0;
}
