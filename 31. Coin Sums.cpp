#include<bits/stdc++.h>
using namespace std;
int dp[201][10];
int solve(vector<int>& coins, int idx, int total) {
    if (total == 0) return 1;
    if (total < 0) return 0;

    if (dp[total][idx] != -1) return dp[total][idx];
    int res = 0;
    for (int i = idx; i < coins.size(); i++) {
        res += solve(coins, i, total - coins[i]);
    }

    return dp[total][idx] = res;
}
int main () {
    memset(dp, -1, sizeof(dp));
    vector<int>coins{1, 2, 5, 10, 20, 50, 100, 200};
    int total = 200;

    int res = solve(coins, 0, total);
    cout << res << endl;
    return 0;
}