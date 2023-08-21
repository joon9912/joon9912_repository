#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int N, rD, rA, rB;
map<string, string> m;

void init() {
    m.insert({"ADD", "0000"});
    m.insert({"SUB", "0001"});
    m.insert({"MOV", "0010"});
    m.insert({"AND", "0011"});
    m.insert({"OR", "0100"});
    m.insert({"NOT", "0101"});
    m.insert({"MULT", "0110"});
    m.insert({"LSFTL", "0111"});
    m.insert({"LSFTR", "1000"});
    m.insert({"ASFTR", "1001"});
    m.insert({"RL", "1010"});
    m.insert({"RR", "1011"});
}

string make_binary(int x, bool isThree) {
    // 0 <= x <= 7
    // 0 <= C# <= 15
    string ret = "";
    int y;

    while (x > 0) {
        y = x % 2;
        x = x / 2;

        if (y == 0)
            ret += "0";
        else
            ret += "1";
    }

    reverse(ret.begin(), ret.end());

    if (isThree) {
        if (ret.length() == 0) return "000";
        if (ret.length() == 1) return "00" + ret;
        if (ret.length() == 2) return "0" + ret;
        return ret;
    }
    else {
        if (ret.length() == 0) return "0000";
        if (ret.length() == 1) return "000" + ret;
        if (ret.length() == 2) return "00" + ret;
        if (ret.length() == 3) return "0" + ret;
        return ret;
    }
}

int main() {
    init();

    string str;

    cin >> N;

    for (int i = 0; i < N; ++i) {
        string result = "";

        cin >> str;

        if (str[str.length() - 1] == 'C') {
            result += m[str.substr(0, str.length() - 1)];
            result += "10";

            cin >> rD >> rA >> rB;

            result += make_binary(rD, true);
            if (str == "MOVC")
            {
                result += "000";
            }
            else
                result += make_binary(rA, true);
            result += make_binary(rB, false);
        }
        else {
            result += m[str];
            result += "00";

            cin >> rD >> rA >> rB;

            result += make_binary(rD, true);
            if (str == "MOV" || str =="NOT")
            {
                result += "000";
            }
            else
                result += make_binary(rA, true);
            result += make_binary(rB, true);
            result += "0";
        }

        cout << result << "\n";
    }

    ;
    return 0;
}
