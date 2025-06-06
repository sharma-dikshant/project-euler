#include <bits/stdc++.h>
using namespace std;

int main()
{

    int res = -1;
    int reci_pt = 0;
    for (int d = 1; d <= 1000; d++) {
        unordered_map<int, int>mp;
        int rem = 1;
        int cnt = 0;
        while (rem != 0 and mp.find(rem) == mp.end()) {
            mp[rem] = cnt;
            rem = (rem % d) * 10;
            cnt++;
        }

        if (cnt - mp[rem] + 1 > reci_pt) {
            reci_pt = cnt + 1;
            res = d;
        }
    }

    cout << res << endl;
   return 0;
}