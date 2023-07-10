#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;

int N, C, x, y;
map<int, int> order; // idx 저장
map<int, int> m;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second == p2.second)
        return order[p1.first] < order[p2.first];

    return p1.second > p2.second;
}

int main() {
    cin >> N >> C;

    for (int i = 0; i < N; ++i) {
        cin >> x;

        m[x]++;
        if (order[x] == 0)
            order[x] = i + 1;
    }

    vector<pair<int, int>> vec(m.begin(), m.end());

    sort(vec.begin(), vec.end(), compare);

    for (auto e : vec) {
        for (int i = 0; i < e.second; ++i) {
            cout << e.first << " ";
        }
    }
    return 0;
}
