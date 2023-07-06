#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
string str;
vector<string> v;

bool compare(string s1, string s2) {
    if (s1.length() != s2.length())
        return s1.length() < s2.length();
    else
        return s1 < s2;
}

int main() {
    cin >> N;

    string s = "";
    for (int i = 0; i < N; ++i) {
        cin >> str;

        for (int j = 0; j < str.length(); ++j) {
            if (str[j] <= '9' && str[j] >= '0') {
                s += str[j];
            }
            else {
                while (s.length() != 1 && s[0] == '0') {
                    s = s.substr(1);
                }
                if (s != "") {
                    v.push_back(s);
                    s = "";
                }
            }
        }
        while (s.length() != 1 && s[0] == '0') {
            s = s.substr(1);
        }
        if (s != "") {
            v.push_back(s);
            s = "";
        }
    }

    sort(v.begin(), v.end(), compare);

    for (auto e : v)
        cout << e << "\n";

    return 0;
}