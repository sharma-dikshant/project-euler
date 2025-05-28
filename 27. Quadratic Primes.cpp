#include <bits/stdc++.h>
using namespace std;

bool isPrime(int val) {
    for (int i = 2; i * i <= val; i++) {
        if (val % i == 0) return false;
    }

    return true;
}

int solve(int a, int b) {
    // eq => n^2 + an + b;
    int n = 0;
    int val = n*n + a*n + b;
    int t_prime = 0;
    while (isPrime(val)) {
        t_prime++;
        n++;
        val = n*n + a*n + b;
    }

    return t_prime;
}

int main() {

    int max_b = 1000;
    int max_a = 1000;

    int max_prime = 0;
    int res = 0;
    pair<int, int>_res;
    for (int a = -1*max_a + 1; a < max_a; a++) {
        for (int b = 2; b < max_b; b++) {

            if (isPrime(b)) {
                int curr = solve(a, b);
                if (curr > max_prime) {
                    max_prime = curr;
                    res = a * b;
                    _res = {a, b};
                }
            }
        }
    }


    cout << res << endl;
    cout << max_prime << endl;
    cout << _res.first << " " << _res.second << endl;

    return 0;
}