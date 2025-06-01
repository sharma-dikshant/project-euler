#include<bits/stdc++.h>
using namespace std;

bool isValid(int i, vector<bool>& sieve) {
    if (i / 10 == 0) return true;
    int temp = i;
    // 717 / 10 => 71 / 10 => 7
    while(temp > 0) {
        if (!sieve[temp]) return false;
        temp /= 10;
    }

    temp = i;
    // 123 => 23 
    while (temp > 0) {
        if (!sieve[temp]) return false;
        int p = log10(temp);
        int d = static_cast<int>(round(pow(10, p)));
        temp %= d;
    }

    return true;
}

int main() {

    int max_n = 1000000; // 1 Million
    vector<bool>sieve(max_n + 1, true);
    sieve[0] = sieve[1] = false;

    for (int i = 2; i * i <= max_n; i++) {
        if (!sieve[i]) continue;
        for (int j = i*2; j <= max_n; j+=i) {
            sieve[j] = false;
        }
    }

    int cnt = 0;
    int res = 0;
    for (int i = 10; i <= max_n; i++) {
        if (!sieve[i]) continue;
        if (isValid(i, sieve)) {
            cout << i << endl;
            cnt += 1;
            res += i;
        }
        if (cnt == 11) break;
    }

    cout << res << endl;

return 0;
}