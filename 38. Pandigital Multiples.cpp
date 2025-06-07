#include<bits/stdc++.h>
using namespace std;


bool isPandigital(string& temp) {
    if (temp.length() != 9) return false;
    unordered_set<char>st;
    for (auto& ch: temp) {
        if (ch == '0' || st.find(ch) != st.end()) return false;
        st.insert(ch);
    }

    return true;
}

int main() {

    int res = 918273645;
    for (int n = 1; n <= 100000; n++) {
        string temp = "";
        int i = 1;
        while (temp.length() < 9) {
            int curr = n * i;
            temp += to_string(curr);
            i++;
        }

        if (isPandigital(temp)) {
            int _temp = stoi(temp);
            res = max(res, _temp);
        }
    }

    cout << res << endl;

return 0;
}