#include<bits/stdc++.h>
using namespace std;

int main() {

    int limit = 1000000; // 1 Million
    vector<bool> sieve(limit, true);

    for (int i = 2; i*i <= limit; i++) {
        if (!sieve[i]) continue;
        for (int j = 2 * i; j < limit; j+=i) sieve[j] = false;
    }

    vector<int>prime;
    vector<long long>prefix;
    long long t = 0;

    for (int i = 2; i < limit; i++) {
        if (sieve[i]) {
            prime.push_back(i);
            t += i;
            prefix.push_back(t);
        }
    }

    int maxLen   = 0;
    int resPrime = -1;

    for (int i = 0; i < prefix.size(); i++) {
        for (int j = i - maxLen; j >= 0; j--) {
            long long diff = prefix[i] - prefix[j];
            if (diff > limit) break;
            if (sieve[diff]) {
                maxLen = i - j;
                resPrime = diff;
            }
        }
    }

    cout << maxLen << endl;
    cout << resPrime << endl;

return 0;
}