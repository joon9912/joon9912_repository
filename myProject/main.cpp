#include <iostream>
using namespace std;

int loc[21];

int main() {
    int N, M, J;
    int dist = 0;

    cin >> N >> M;
    cin >> J;

    for (int i = 1; i <= J; ++i) {
        cin >> loc[i];
    }


    cout << dist << endl;

    return 0;
}