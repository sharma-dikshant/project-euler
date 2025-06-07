#include<bits/stdc++.h>
using namespace std;

int fact(int n) {
    int res = 1;
    while (n--) res *= (n + 1);

    return res;
}

bool isValid(int n) {
    string s = to_string(n);
    int res = 0;
    
    for (auto& ch: s) {
        res += fact((ch - '0'));
    }
    return n == res;
}

int main() {

    int res = 0;
    int limit = 1000000; // 1 Million
    // max digital fact => fact(9) = 362880
    for (int i = 10; i <= limit; i++) {
        if (isValid(i)) {
            res += i;
            cout << i << endl;
        }
    }

    cout << "res: " << res << endl;

return 0;
}