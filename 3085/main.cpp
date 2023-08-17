#include <iostream>
using namespace std;

int N;
char arr[51][51];
int m;

void check() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int k = j;
            int len = 0; // go right
            while (k < N) {
                if (arr[i][j] == arr[i][k])
                    len++;
                else
                    break;
                k++;
            }
            m = max(m, len);

            k = i;
            len = 0; // go down
            while (i < N) {
                if (arr[i][j] == arr[k][j])
                    len++;
                else
                    break;
                k++;
            }
            m = max(m, len);
        }
    }
}

void swap(char &c1, char &c2) {
    char tmp = c1;
    c1 = c2;
    c2 = tmp;
}

void exchange() {
    int dx[] {-1,0, 1, 0};
    int dy[] {0, 1, 0, -1};

    for (int k = 0; k < N; ++k) {
        for (int j = 0; j < N; ++j) {
            for (int i = 0; i < 4; ++i) {
                int nx = k + dx[i];
                int ny = j + dy[i];

                if (nx == -1)   nx = N - 1;
                if (nx == N)    nx = 0;
                if (ny == -1)   ny = N - 1;
                if (ny == N)    ny = 0;

                swap(arr[k][j], arr[nx][ny]);
                check();
                swap(arr[k][j], arr[nx][ny]);
            }
        }
    }
}

int main() {
    string s;

    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> s;
        for (int j = 0; j < s.length(); ++j)
            arr[i][j] = s[j];
    }

    exchange();

    cout << m << endl;

    return 0;
}
