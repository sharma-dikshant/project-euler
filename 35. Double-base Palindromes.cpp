#include <bits/stdc++.h>
using namespace std;

bool isPali10(int n) {
    if (n < 10) return true;
    string num = to_string(n);
    int i = 0, j = num.length() - 1;

    while (i < j) {
        if (num[i] != num[j]) return false;
        i++; j--;
    }
    return true;
}

bool isPali2(int n) {
    int i = log2(n);
    int j = 0;

    while (i > j) {
        int left = ((n >> i) & 1);
        int right = ((n >> j) & 1);
        if (left != right) return false;
        i--; j++;
    }

    return true;
}

int main() {
    int max_n = 1000000; // 1 Million
    int res = 0;

    for (int i = 1; i <= max_n; i++) {
        if (isPali10(i) && isPali2(i)) {
            cout << i << endl;
            res += i;
        }
    }

    cout << res << endl;

    return 0;
}