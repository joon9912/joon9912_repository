#include <iostream>
using namespace std;

int T, M, N, K, X, Y;
int arr[51][51];
bool visited[51][51];
int di[] { -1, 0, 0, 1};
int dj[] { 0, -1, 1, 0};

void arr_check(int i, int j) {
    // cout << "hello\n";
    int ni, nj;
    for (int k = 0; k < 4; ++k) {
        ni = i + di[k];
        nj = j + dj[k];

        if (ni >= 0 && nj >= 0
            && ni < N && nj < M
            && !visited[ni][nj] && arr[ni][nj])
        {
            visited[ni][nj] = true;
            arr_check(ni, nj);
        }
    }
}

void dfs(int &res) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (!visited[i][j] && arr[i][j]) {
                // cout << i << " " << j << endl;
                visited[i][j] = true;
                arr_check(i, j);
                res++;
            }
        }
    }
}

void arr_clear() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            arr[i][j] = visited[i][j] = 0;
        }
    }
}

void print_arr() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int res = 0;

    cin >> T;

    for (int j = 0; j < T; ++j) {
        cin >> M >> N >> K;
        for (int i = 0; i < K; ++i) {
            cin >> Y >> X;
            arr[X][Y] = 1;
        }
        dfs(res);

        cout << res << endl;

        arr_clear();
        res = 0;
    }

    return 0;
}
