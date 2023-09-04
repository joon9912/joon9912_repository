#include <iostream>
#include <vector>
using namespace std;

// adjacent list with vector

int main() {
    // directed graph
    // not use index 0
    vector<int> w[6];

    w[1].push_back(2);
    w[1].push_back(4);
    w[2].push_back(3);
    w[3].push_back(4);
    w[4].push_back(2);
    w[4].push_back(5);

    for (int i = 1; i <= 5; ++i) {
        for (auto e : w[i]) {
            cout << i << " -> " << e << "\n";
        }
    }
    return 0;
}
