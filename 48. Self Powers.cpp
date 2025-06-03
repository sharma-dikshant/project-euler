#include<bits/stdc++.h>
using namespace std;

vector<int> calPow (int n) {
    vector<int>res(10, 0);
    res[0] = 1;

    for (int i = 0; i < n; i++) {
        int carry = 0;
        for (int d = 0; d < 10; d++) {
            int curr = res[d] * n + carry;
            res[d]   = curr % 10;
            carry = curr / 10; 
        }
    }
    return res;
}

int main() {

    vector<int>res(10, 0);

    for (int i = 1; i <= 1000; i++) {
        vector<int> pow = calPow(i);
        int carry = 0;
        for (int j = 0; j < 10; j++) {
            int curr = res[j] + pow[j] + carry;
            res[j] = curr % 10;
            carry = curr / 10;
        }
    }

    for (int i = 9; i >= 0; i--) cout << res[i];
    cout << endl;

    return 0;
}