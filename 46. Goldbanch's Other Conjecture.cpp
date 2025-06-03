#include<bits/stdc++.h>
using namespace std;

int main() {

    int max_num = 1000000; // 1 Million
    vector<bool>sieve(max_num + 1, true);

    int last_prime = 2;
    for (int i = 2; i <= max_num; i++) {
        if (!sieve[i] && i % 2 != 0) {
            int n = i;
            bool found = false;
            for (int i = last_prime; i >= 2; i--) {
                if (sieve[i]) {
                    int t = (n - i) / 2;
                    int sqrtT = sqrt(t);
                    if (sqrtT * sqrtT == t) {
                        found = true;
                        break;
                    }
                }
            }

            if (!found) {
                cout << n << endl;
                break;
            }

            continue;
        }
        last_prime = i;
        for (int j = 2 * i; j <= max_num; j += i) {
            sieve[j] = false;
        }
    }


return 0;
}       