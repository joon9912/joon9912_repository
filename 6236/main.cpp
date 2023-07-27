#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> v;

int main() {
    int x;

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        cin >> x;
        v.push_back(x);
    }
    return 0;
}
