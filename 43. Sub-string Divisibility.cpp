#include<bits/stdc++.h>
using namespace std;

void solve(int idx, vector<int>& num, long long& res, unordered_set<int>&st) {
    if (idx == 10) {
        if ((num[7]*100 + num[8]*10 + num[9]) % 17 != 0) return;

        long long curr = 0;
        for (int i = 0; i < 10; i++) {
            curr *= 10;
            curr += num[i];
        }

        res += curr;
    }

    if (idx > 3 && (num[1]*100 + num[2]*10 + num[3]) % 2 != 0) return;
    if (idx > 4 && (num[2]*100 + num[3]*10 + num[4]) % 3 != 0) return;
    if (idx > 5 && (num[3]*100 + num[4]*10 + num[5]) % 5 != 0)  return;
    if (idx > 6 && (num[4]*100 + num[5]*10 + num[6]) % 7 != 0)  return;
    if (idx > 7 && (num[5]*100 + num[6]*10 + num[7]) % 11 != 0) return;
    if (idx > 8 && (num[6]*100 + num[7]*10 + num[8]) % 13 != 0) return;

    for (int i = 0; i < 10; i++) {
        if (st.find(i) != st.end()) continue;
        if (idx == 0 && i == 0) continue;
        num[idx] = i;
        st.insert(i);
        solve(idx + 1, num, res, st);
        st.erase(i);
    }
}

int main() {

    vector<int>num(10, -1);
    long long res = 0;
    unordered_set<int>st;
    solve(0, num, res, st);

    cout << "res :" << res << endl;

return 0;
}