#include <iostream>
#include <string>
using namespace std;

int N;
int alphabet[26];

int main() {
    string name, selects;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> name;

        alphabet[int(name[0]) - 97]++;
    }

    selects = "";
    for (int i = 0; i < 26; ++i) {
        if (alphabet[i] >= 5) {
            selects += char(i + 97);
        }
    }

    if (selects != "")
        cout << selects << endl;
    else
        cout << "PREDAJA\n";
    return 0;
}