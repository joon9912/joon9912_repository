#include <iostream>
#include <vector>
using namespace std;

int N, x, maximum;
vector<int> v;

int main() {
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> x;
        v.push_back(x);
    }

    int honeycomb;
    for (int i = 0; i < N; ++i) {
        honeycomb = i;

        int h1 = 0 , h2 = 0;
        while (h1 == honeycomb) {
            h1++;
        }
        while (h2 == honeycomb || h1 == h2) {
            h2++;
        }
        // cout << h1 << " " << h2 << "\n";

        while (1) {
            int s1 = 0, s2 = 0;
            if (h1 < honeycomb && h2 < honeycomb) {
                for (int j = h1 + 1; j <= honeycomb; ++j) {
                    if (j != h2)
                        s1 += v[j];
                }
                for (int j = h2 + 1; j <= honeycomb; ++j){
                    s2 += v[j];
                }
            }
            if (h1 < honeycomb && h2 > honeycomb) {
                for (int j = h1 + 1; j <= honeycomb; ++j) {
                    s1 += v[j];
                }
                for (int j = honeycomb; j < h2; ++j) {
                    s2 += v[j];
                }
            }
            if (h1 > honeycomb && h2 > honeycomb) {
                for (int j = honeycomb; j < h1; ++j) {
                    s1 += v[j];
                }
                for (int j = honeycomb; j < h2; ++j) {
                    if (j != h1)
                        s2 += v[j];
                }
            }
            // cout << h1 << " " << h2 << " " << s1 + s2 << "\n" ;
            maximum = max(maximum, s1 + s2);

            do {
                h2++;
            } while (h2 == honeycomb);

            if (h2 == N) {
                do {
                    h1++;
                } while (h1 == honeycomb);
                h2 = h1 + 1;
                while (h2 == honeycomb) {
                    h2++;
                }
            }
            if (h2 == N)
                break;
        }
    }

    cout << maximum << endl;

    return 0;
}

/*

 */