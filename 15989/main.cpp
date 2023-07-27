#include <iostream>
#include <vector>
using namespace std;

int T, n;
int arr[10001];
vector<int> v;

int main() {
    int m = 0;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> n;
        m = max(m, n);
        v.push_back(n);
    }
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3; // 1 + 1 + 1 , 1 + 2 , 3
    arr[4] = 4;
    arr[5] = 5;
    for (int i = 6; i <= m; ++i) {
        arr[i] = arr[i - 3] + (arr[i - 2] - arr[i - 5]) + 1;
    }

    for (auto e : v)
        cout << arr[e] << endl;
    return 0;
}
