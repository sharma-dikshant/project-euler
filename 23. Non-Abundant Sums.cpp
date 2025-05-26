#include<bits/stdc++.h>
using namespace std;

int main () {
    int max_limit = 28123;
    vector<int>arr(max_limit, 0);
    vector<int>ab_nums;

    for (int i = 1; i <= max_limit / 2;i++) {
        for (int j = 2 * i; j < max_limit; j+=i) {
            arr[j] += i;
        }
    }
    for (int i = 1; i < max_limit; i++) {
        if (arr[i] > i) {
            ab_nums.push_back(i);
        }
    }

    unordered_set<int>st;
    for (int i = 0; i < ab_nums.size() - 1; i++) {
        for (int j = i; j < ab_nums.size(); j++) {
            if (ab_nums[i] + ab_nums[j] <= max_limit) st.insert(ab_nums[i] + ab_nums[j]);
        }
    }

    cout << st.size() << endl;
    int res = 0;
    for (int i = 1; i < max_limit; i++) {
        if (st.find(i) == st.end()) res += i;
    }

    cout << res << endl;

    return 0;
    
}