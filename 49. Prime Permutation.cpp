#include<bits/stdc++.h>
using namespace std;

string solve(unordered_set<int>& st) {
    string res = "";
    for (auto a: st) {
        for (auto c: st) {
            int b2 = a + c;
            if (a != c && b2 % 2 == 0 && st.find(b2 / 2) != st.end()) {
                res += to_string(c) + to_string(b2 / 2) + to_string(a);
                return res;
            }
        }
    }

    return res;
}

int main() {

    vector<bool>sieve(10000, true);
    for (int i = 2; i * i <= 10000; i++) {
        if (!sieve[i]) continue;
        for (int j = 2 * i; j < 10000; j+=i) sieve[j] = false;
    }

    string res;
    int cnt = 0;
    for (int i = 1000; i < 10000; i++) {
        if (!sieve[i]) continue;

        unordered_set<int>curr;
        vector<int>temp(4);

        int t = i, j = 3;
        while (t) {
            temp[j--] = t % 10;
            t /= 10;
        }

        do {
            int curr_n = 0;
            for (int j = 0; j < 4; j++) {
                curr_n *= 10;
                curr_n += temp[j];
            }
           if (sieve[curr_n]) curr.insert(curr_n);
        } while (next_permutation(temp.begin(), temp.end()));

        if (curr.size() >= 3) res = solve(curr);
        if (res.length() == 12) {
            cout << res << endl;
            res = "";
            cnt++;
        }
        if (cnt == 2) break;

    }


return 0;
}
