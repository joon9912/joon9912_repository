#include <iostream>
using namespace std;

int N, M;
int arr[7][7];
int di[]{1,1,1};
int dj[]{-1, 0, 1};
int res = 1000000000;

void select(int x, int y, int z, int sum) {
    sum += arr[x][y];
    if (x == N - 1 && y >= 0 && y < M)
        res = min(res, sum);
    else if (x >= 0 && x < N && y >= 0 && y < M) {
        for (int i = 0; i < 3; ++i)
            if (i != z)
                select(x + di[i], y + dj[i], i, sum);
    }
}

void start(int x, int y) {
    int sum = arr[x][y];

    for (int i = 0; i < 3; ++i)
        select(x + di[i], y + dj[i],  i, sum);
}

int main() {
    // i, j -> i + 1, j - 1 or i + 1, j or i + 1, j + 1

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> arr[i][j];
        }
    }

    int sum = 0;
    for (int j = 0; j < M; ++j) {
        start(0, j);
    }

    cout << res << endl;

    return 0;
}
