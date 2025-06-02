#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isPandigital(int& n) {
    int len = to_string(n).length();
    vector<int>arr(len + 1, 0);
    int t = n;
    while (t) {
        int d = t % 10;
        if (arr[d] >= 1 || d > len || d == 0) return false;
        arr[d]++;
        t /= 10;
    }

    return true;
}

bool isprime(int& n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }

    return true;
}

int main() {
    // int max_num = 7654321;
    // vector<bool>sieve(max_num + 1, true);

    // for (int i = 2; i * i <= max_num; i++) {
    //     for (int j = 2 * i; j <= max_num; j += i) sieve[j] = false;
    // }

    int i = 7654321;
    for (; i >= 1; i--) {
        if (isprime(i) && isPandigital(i)) break;
    }

    cout << i << endl;

    return 0;
}