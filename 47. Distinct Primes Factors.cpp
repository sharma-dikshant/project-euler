#include <bits/stdc++.h>
using namespace std;

int main () {
    int max_num = 1000000; 

    vector<int>res;

    for (int i = 210; i < max_num; i++) {
        int n = i;
        unordered_set<int>st;
        //prime factorize
        while (n % 2 == 0) {
            st.insert(2);
            n /= 2;
        }

        for (int j = 3; j * j <= n; j+=2) {
            while (n % j == 0) {
                st.insert(j);
                n /= j;
            }
        }
        if (n > 2) st.insert(n);
        if (st.size() == 4) res.push_back(i);
        if (st.size() != 4) res.clear();
        if (res.size() == 4) {
            cout << res[0] << endl;
            break;
        }
    }

    return 0;
}