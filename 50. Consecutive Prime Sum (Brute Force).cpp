#include<bits/stdc++.h>
using namespace std;

int main() {

    int limit = 1000000; // 1m
    vector<int>sieve(limit, true);
    vector<int>primes;
    int x = 2;
    for (; x * x <= limit; x++) {
        if (!sieve[x]) continue;
        primes.push_back(x);
        for (int j = 2*x; j < limit; j+=x) sieve[j] = false;
    }
    for (; x < limit; x++) {
        if (sieve[x]) primes.push_back(x);
    }
    
    int n = primes.size();
    vector<long long>prefix(n);
    long long t = 0;
    for (int i = 0; i < n; i++) {
        t += primes[i];
        prefix[i] = t;
    }

    int res = 0;
    int p = -1;
    for (int i = 0; i < n; i++) {
        if (prefix[i] < limit && sieve[prefix[i]]) {
           if (i + 1 > res) {
                res = i + 1;
                p = prefix[i];
           }
            continue;
        }
        for (int j = 0; j < i; j++) {
            long long diff = prefix[i] - prefix[j];
            if (diff < limit && sieve[diff]) {
                if (i - j > res) {
                    res = i - j;
                    p = diff;
                }
                break;
            }
        }
    }

    cout << res << endl;
    cout << p << endl;

return 0;
}