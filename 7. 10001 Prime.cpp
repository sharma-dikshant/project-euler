#include <bits/stdc++.h>
using namespace std;

int main () {
    int max_range = 10001;

    int curr = 2;
    while (max_range) {
        bool isPrime = true;
        for (int i = 2; i * i <= curr; i++) {
            if (curr % i == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            max_range -= 1;
        }

        if (max_range == 0) break;
        curr++;
    }

    cout << curr << endl;
}