#include <iostream>
#include <string>
using namespace std;

int s;
string n;
char num[10][23][12];
// 1 <= s <= 10
// 3 <= s + 2 <= 12
// 5 <= 2s + 3 <= 23

void init(int size) {
    int x = size + 2;
    int y = 2 * size + 3;

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < x; ++k)
                num[i][j][k] = ' ';
        }
    }

    // num[0]
    for (int i = 1; i < x - 1; ++i) {
        num[0][0][i] = '-';
        num[0][y - 1][i] = '-';
    }
    for (int i = 1; i <= s; ++i) {
        // left
        num[0][i][0] = '|';
        num[0][y - 1 - i][0] = '|';
        // right
        num[0][i][x - 1] = '|';
        num[0][y - 1 - i][x - 1] = '|';
    }

    // num[1]
    for (int i = 1; i <= s; ++i) {
        num[1][i][x - 1] = '|';
        num[1][y - 1 - i][x - 1] = '|';
    }

    // num[2]
    for (int i = 1; i < x - 1; ++i) {
        num[2][0][i] = '-';
        num[2][y - 1][i] = '-'; // middle
        num[2][y / 2][i] = '-';
    }
    for (int i = 1; i <= s; ++i) {
        num[2][i][x - 1] = '|';
        num[2][y - 1 - i][0] = '|';
    }

    // num[3]
    for (int i = 1; i < x - 1; ++i) {
        num[3][0][i] = '-';
        num[3][y - 1][i] = '-'; // middle
        num[3][y / 2][i] = '-';
    }
    for (int i = 1; i <= s; ++i) {
        num[3][i][x - 1] = '|';
        num[3][y - 1 - i][x - 1] = '|';
    }

    // num[4]
    for (int i = 1; i <= s; ++i) {
        num[4][i][0] = '|';
        // num[4][y - 1 - i][0] = '|';
        num[4][i][x - 1] = '|';
        num[4][y - 1 - i][x - 1] = '|';
    }
    for (int i = 1; i < x - 1; ++i) {
        num[4][y / 2][i] = '-'; // middle
    }

    // num[5]
    for (int i = 1; i < x - 1; ++i) {
        num[5][0][i] = '-';
        num[5][y - 1][i] = '-'; // middle
        num[5][y / 2][i] = '-';
    }
    for (int i = 1; i <= s; ++i) {
        num[5][i][0] = '|';
        num[5][y - 1 - i][x - 1] = '|';
    }

    // num[6]
    for (int i = 1; i < x - 1; ++i) {
        num[6][0][i] = '-';
        num[6][y - 1][i] = '-'; // middle
        num[6][y / 2][i] = '-';
    }
    for (int i = 1; i <= s; ++i) {
        num[6][i][0] = '|';
        num[6][y - 1 - i][0] = '|';
        num[6][y - 1 - i][x - 1] = '|';
    }

    // num[7]
    for (int i = 1; i <= s; ++i) {
        num[7][i][x - 1] = '|';
        num[7][y - 1 - i][x - 1] = '|';
    }
    for (int i = 1; i < x - 1; ++i) {
        num[7][0][i] = '-';
    }

    // num[8]
    for (int i = 1; i < x - 1; ++i) {
        num[8][0][i] = '-';
        num[8][y / 2][i] = '-';
        num[8][y - 1][i] = '-';
    }
    for (int i = 1; i <= s; ++i) {
        // left
        num[8][i][0] = '|';
        num[8][y - 1 - i][0] = '|';
        // right
        num[8][i][x - 1] = '|';
        num[8][y - 1 - i][x - 1] = '|';
    }

    // num[9]
    for (int i = 1; i < x - 1; ++i) {
        num[9][0][i] = '-';
        num[9][y / 2][i] = '-';
        num[9][y - 1][i] = '-';
    }
    for (int i = 1; i <= s; ++i) {
        // left
        num[9][i][0] = '|';
        // right
        num[9][i][x - 1] = '|';
        num[9][y - 1 - i][x - 1] = '|';
    }
}

int main() {
    cin >> s >> n;

    init(s);

    for (int i = 0; i < 2 * s + 3; ++i) {
        for (int k = 0; k < n.length(); ++k) {
            int t = n[k] - '0';

            for (int j = 0; j < s + 2; ++j) {
                cout << num[t][i][j];
            }
            if (i == 2 * s + 2 && k == n.length() - 1) return 0;
            cout << " ";
        }
        // if (i == 2 * s + 2) break;
        cout << endl;
    }
    return 0;
}
