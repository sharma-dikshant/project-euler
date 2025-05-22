#include<bits/stdc++.h>
using namespace std;

int main () {
    int max_range = 4000000; // 4 Million
    int res = 0, fir = 1, sec = 2, curr = 0;

    while (curr <= max_range) {
        curr = fir + sec;
        if (curr % 2 == 0) {
            res += curr;
        }

        fir = sec;
        sec = curr;
    }

    // adding 2 explicitly as it was skipped 
    res += 2;
    cout << res << endl;
}