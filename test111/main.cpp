#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
vector<int> v;

int main() {
    int n;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> n;
            v.push_back(n);
        }
        sort(v.begin(), v.end());

        cout << v[7] << endl;

        v.clear();
    }

    return 0;
}