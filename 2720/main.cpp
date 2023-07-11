#include <iostream>
using namespace std;

int T, C;
int x, y, z, w;

int main() {
    cin >> T;

    for (int i = 0; i < T; ++i) {
        cin >> C;

        x = C / 25;
        C = C % 25;
        y = C / 10;
        C = C % 10;
        z = C / 5;
        C = C % 5;
        w = C / 1;

        cout << x << " " << y << " "
            << z << " " << w << "\n";
    }
    return 0;
}
