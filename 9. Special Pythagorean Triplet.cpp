#include <bits/stdc++.h>
using namespace std;

int main () {
    int target_sum = 1000;
    
    for (int a = 1; a <= target_sum - 2; a++) {
        for (int b = a + 1; b <= target_sum - 2; b++) {
            int c = target_sum - (a + b);
            if (a * a + b * b == c * c) {
                int res = a * b * c;
                cout << a << endl;
                cout << b << endl;
                cout << c << endl;
                cout << res << endl;
                break;
            }
        }
    }

    return 0;
}