#include <iostream>
#include <string>
using namespace std;

int N;
string new_str[5]{"", "", "", "", ""};
string num_arr[5];
string arr[5];
string ans;
// 가로 길이 : N / 5
// 세로 길이 : 5

void init() {
    // 0 (idx : 0 ~ 2), 1 (idx : 4 ~ 6 .#.), 2 (idx : 8 ~ 10) ...
    // n (idx : 4 * n, 4 * n + 2) but only 2 is 5
    num_arr[0] = "###..#..###.###.#.#.###.###.###.###.###";
    num_arr[1] = "#.#..#....#...#.#.#.#...#.....#.#.#.#.#";
    num_arr[2] = "#.#..#..###.###.###.###.###...#.###.###";
    num_arr[3] = "#.#..#..#.....#...#...#.#.#...#.#.#...#";
    num_arr[4] = "###..#..###.###...#.###.###...#.###.###";
}

bool compare(int x) {
    int nx = 4 * x;

    for (int i = nx; i < nx + 3; ++i) {
        if (num_arr[0][i] != new_str[0][i - nx])
            return false;
        if (num_arr[1][i] != new_str[1][i - nx])
            return false;
        if (num_arr[2][i] != new_str[2][i - nx])
            return false;
        if (num_arr[3][i] != new_str[3][i - nx])
            return false;
        if (num_arr[4][i] != new_str[4][i - nx])
            return false;
    }

    // for (int i = 0; i < 5; ++i)
    //     cout << num_arr[i][nx] << num_arr[i][nx + 1] << num_arr[i][nx + 2] << endl;
    return true;
}

void print_str() {
    for (int i = 0; i < 5; ++i)
        cout << new_str[i] << "\n";
}

bool isOne() {
    if (new_str[0][0] == '#' && new_str[0][1] == '.'
    && new_str[1][0] == '#' && new_str[1][1] == '.'
    && new_str[2][0] == '#' && new_str[2][1] == '.'
    && new_str[3][0] == '#' && new_str[3][1] == '.'
    && new_str[4][0] == '#' && new_str[4][1] == '.')
    {
        return true;
    }

    return false;
}

int main() {
    char c;
    ans = "";

    init();

    cin >> N;

    for (int i = 0; i < 5; ++i) {
        string s = "";
        for (int j = 0; j < N / 5; ++j) {
            cin >> c;
            s += c;
        }
        arr[i] = s;
        // cout << arr[i] << endl;
    }

    if (N == 5 || N == 10) {
        cout << 1;
        return 0;
    }

    for (int j = 0; j < N / 5; j++) {
        if (arr[0][j] != '#') continue;
        if (j == N / 5 - 1) {
            ans += "1";
            break;
        }
        for (int k = 0; k < 5; ++k) {
            new_str[k] += arr[k][j];
            new_str[k] += arr[k][j + 1];
            new_str[k] += arr[k][j + 2];
        }

        // print_str();

        if (isOne()) {
            ans += "1";
            j++;
        }
        else { // not 1
            for (int i = 0; i < 10; ++i) {
                if (i == 1) continue;
                if (compare(i)) {
                    ans += i + '0';
                    break;
                }
            }
            j += 3;
        }

        for (int i = 0; i < 5; ++i)
            new_str[i] = "";
    }

    cout << ans;

    return 0;
}
