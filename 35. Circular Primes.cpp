#include<bits/stdc++.h>
using namespace std;

int main () {
    int max_cnt = 1000000; // i Million
    vector<bool>sieve(max_cnt + 1, true);
    sieve[0] = sieve[1] = false;

    for (int i = 2; i <= max_cnt; i++) {
        if (!sieve[i]) continue;
        for (int j = 2 * i; j <= max_cnt; j+=i) {
            sieve[j] = false;
        }
    }

    int res = 0;

    for (int n = 11; n <= max_cnt; n++) {
        if (!sieve[n]) continue;
        string org = to_string(n);
        int i = 0;  // total i permutation 
        bool isValid = true;
        while (i < org.length()) {
            string temp = "";
            int j = 0;  // curr len
            int idx = i;
            while (j < org.length()) {
                temp += org[idx];
                j++;
                idx = (idx + 1) % org.length();
            }
                
            if (!sieve[stoi(temp)]) {
                isValid = false;
                break;
            }
            i++;
            // cout << temp << endl;
        }
        if (isValid) {
            cout << n << endl;
            res += 1;
        };
    }

    res += 4;
    cout << res << endl;

    return 0;
}