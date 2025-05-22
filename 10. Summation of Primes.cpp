#include <bits/stdc++.h>
using namespace std;

int main () {
    int max_range = 2000000; // 2 Million
    long long res = 0;

    int curr = 2;
    while (curr <= max_range) {
        bool isPrime = true;
        for (int i = 2; i * i <= curr; i++) {
            if (curr % i == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) res += curr;
        curr++;
    }

    cout << res << endl;

    return 0;
}