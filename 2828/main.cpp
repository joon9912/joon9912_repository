#include <iostream>
using namespace std;

struct basket {
    int l;
    int r;
};

int main() {
    struct basket b;
    int N, M, J, loc, dist;

    cin >> N >> M;
    cin >> J;

    b.l = 1;
    b.r = M;

    dist = 0;
    for (int i = 0; i < J; ++i) {
        cin >> loc;

        if (loc <= b.r && loc >= b.l)
            continue;
        if (loc > b.r) {
            dist += loc - b.r;
            b.l = (loc - b.r) + b.l;
            b.r = loc;
        }
        else if (loc < b.l) {
            dist += b.l - loc;
            b.r = b.r - (b.l - loc);
            b.l = loc;
        }
    }
    cout << dist << endl;

    return 0;
}
