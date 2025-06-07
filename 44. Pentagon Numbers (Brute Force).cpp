#include <bits/stdc++.h>
using namespace std;

int main() {

    set<int>st;
    for (int n = 1; n <= 10000; n++) {
        int curr = n * (3 * n - 1) / 2;
        st.insert(curr);
    }

    for (auto i: st) {
        for (auto j: st) {
            if (i == j) continue;
            int diff = abs(i - j);
            int sum = i + j;

            if (st.find(diff) != st.end() && st.find(sum) != st.end()) {
                cout << diff << endl;
                return 0;
            }
        }
    }

    return 0;
}