#include <iostream>
using namespace std;

int H, W, height;
int arr[501][501];
int sum;

void print_arr() {
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

int main() {
    cin >> H >> W;

    for (int i = 0; i < W; ++i) {
        cin >> height;

        for (int j = H - 1; j >= H - height; --j)
            arr[j][i] = 1;
    }

    for (int i = H - 1; i >= 0; --i) {
        int left = -1;
        int right = -1;
        for (int j = 0; j < W; ++j) {
            if (arr[i][j] && left == -1)
                left = j;
            else if (left != -1 && arr[i][j])
                right = j;

            if (left != -1 && right != -1) {
                for (int k = left + 1; k < right; ++k) {
                    arr[i][k] = 2;
                    sum++;
                }
                left = j;
                right = -1;
            }
        }
    }

    // print_arr();

    cout << sum << "\n";
    return 0;
}
