#include <bits/stdc++.h>
using namespace std;

bool isPali(int n) {
    string str = to_string(n);
    int i= 0, j = str.length() - 1;

    while (i < j) {
        if (str[i] != str[j]) return false;
        i++; j--;
    }

    return true;
}

int main () {
    int range_start = 100;
    int range_end   = 999;
    int res = -1;

    for (int i = range_end; i >= range_start; i--) {
        for (int j = range_end; j >= range_start; j--) {
            int curr = i * j;
            if (res != -1 && curr < res) break;
            if (isPali(curr)) {
                res = curr;
                break;
            }
        }
    }

    cout << res << endl;

    return 0;
}