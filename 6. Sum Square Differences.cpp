#include <bits/stdc++.h>
using namespace std;

int main() {
    int range_s = 1, range_e = 10;
    int res = 0;

    // (a + b)^2 = a^2 + b^2 + 2ab
    // (a + b + c)^2 = a^2 + b^2 + c^2 + 2(ab + ac + bc)
    // (a + b + c + d)^ = a^2 + b^2 + c^2 + d^2 + 2(ab + ac + ad + bc + bd + cd)
    for (int i = range_s; i <= range_e - 1; i++) {
        for (int j = i + 1; j <= range_e; j++) {
            res += i * j;
        }
    }

    res *= 2;

    cout << res << endl;
}