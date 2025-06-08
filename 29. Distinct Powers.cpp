#include<bits/stdc++.h>
using namespace std;

string pow(int n, int exp) {

    string res = to_string(n);
    reverse(res.begin(), res.end());
    while (exp >= 2) {
        int carry = 0;
        for (int i = 0; i < res.length(); i++) {
            int curr = carry + n * (res[i] - '0');
            res[i] = (curr % 10 + '0');
            carry = curr / 10;
        }
        
        while (carry) {
            res += to_string(carry % 10);
            carry /= 10;
        }
        exp--;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    unordered_set<string>st;
    for (int n = 2; n <= 100; n++) {
        for (int exp = 2; exp <= 100; exp++) {
            st.insert(pow(n, exp));
        }
    }

    // st.insert(pow(2, 50));
    // st.insert(pow(4, 25));

    cout << st.size() << endl;
    // cout << *st.begin() << endl;

return 0;
}