#include <bits/stdc++.h>
using namespace std;

int main () {
    int max_val = 1000000;
    int maxLen = 0;
    int res = 0;
    unordered_map<long long, int> mp;  

    // Here the key observation is that even for a number < 1 Million intermediate values can go beyond it 
    mp[1] = 1;

    for (int i = 2; i <= max_val; i++) {
        long long curr = i;
        int len = 0;

        while (curr != 1 && mp.find(curr) == mp.end()) {
            if (curr % 2 == 0)
                curr /= 2;
            else
                curr = 3 * curr + 1;
            len++;
        }

        len += mp[curr];  
        mp[i] = len;

        if (len > maxLen) {
            maxLen = len;
            res = i;
        }
    }

    cout << res << endl;
}
