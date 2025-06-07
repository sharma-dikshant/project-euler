#include<bits/stdc++.h>
using namespace std;

bool isCurious(int a, int b) {
    if (a % 11 == 0 && b % 11 == 0) return false;
    set<int>_a;
    set<int>_b;

    int t = a;
    while (t) {
        _a.insert(t % 10);
        t /= 10;
    }
    t = b;
    while (t) {
        int d = t % 10;
        if (_a.find(d) != _a.end()) _a.erase(d);
        else _b.insert(d);
        t /= 10;
    }
    if (_a.size() != 1 || _b.size() != 1) return false;
    if (a * *_b.begin() != b * *_a.begin()) return false;

    return true;
}


int gcd(int a, int b) {
    if (b == 0) return a;

    return gcd(b, a % b);
}

int main() {

    int nume = 1;
    int deno = 1;
    for (int i = 10; i <= 99; i++) {
        for (int j = i + 1; j < 100; j++) {
            if (i % 10 == 0 && j % 10 == 0) continue;
            if (isCurious(i, j)) {
                cout << i << "/" << j << endl;
                nume *= i;
                deno *= j;
            }
        }
    }

    int res = deno / gcd(nume, deno);
    cout << res << endl;

    // cout << gcd(2, 7) << endl;

return 0;
}