#include <bits/stdc++.h>
using namespace std;

int main () {

    unordered_map<int, int>mp;
    int range_s = 1;
    int range_e = 10;

    for (int i = range_s; i <= range_e; i++) {
        int curr = i;
        for (int j = 2; j <= curr; j++) {
            int cnt = 0;
            while (curr % j == 0) {
                cnt++;
                curr /= j;
            }
            if (mp.count(j)) {
                mp[j] = max(cnt, mp[j]);
            } else {
                mp[j] = cnt;
            }

            if (curr == 1) break;
        }
    }

    int res = 1;
    for (auto& el: mp) {
        res *= pow(el.first, el.second);
    }

    cout << res << endl;

    return 0;
}