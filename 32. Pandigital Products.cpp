#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b, int c) {
    unordered_set<char>st;
    string str = to_string(a) + to_string(b) + to_string(c);
    if (str.length() != 9) return 0;

    for (auto ch: str) {
        if (st.find(ch) != st.end() || ch == '0') return 0;
        st.insert(ch);
    }

    if (st.size() != 9) return 0;

    return c;
}

int main() {

    /*
        for a x b = c
        there are two valid cases s.t len(a) + len(b) + len(c) == 9
        len(a) = 1  len(b) = 4  len(c) = 4
        len(a) = 2  len(b) = 3  len(c) = 4
    */

    int res = 0;
    unordered_set<int>st;
    for (int a = 1; a <= 9; a++) {
        for (int b = 1000; b <= 9999; b++) {
            if (solve(a, b, a * b) != 0) {
                cout << a << " " << b << " " << a*b << endl;
                st.insert(a * b);
            }
        }
    }
    for (int a = 10; a <= 90; a++) {
        for (int b = 100; b <= 999; b++) {
 
            if (solve(a, b, a * b) != 0) {
                cout << a << " " << b << " " << a*b << endl;
                st.insert(a * b);
            }
        }
    }

    for (auto el: st) res += el;
    cout << res << endl;

    return 0;
}