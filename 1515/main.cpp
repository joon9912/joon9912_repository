#include <iostream>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;

string num;
queue<char> q;

int main() {
    cin >> num;

    int i = 1, j = 0;
    for (;;++i) {
        string str = to_string(i);
        for (int j = 0; j < str.length(); ++j)
            q.push(str[j]);

        while (!q.empty() && j != num.length()) {
            char c = q.front();
            q.pop();
            if (c == num[j])
                j++;
        }

        if (j == num.length())
            break;
    }
    cout << i << endl;

    return 0;
}
