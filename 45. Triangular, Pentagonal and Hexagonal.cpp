#include<bits/stdc++.h>
using namespace std;

int main() {

    // triangular No
    for (int t = 286; ; t++) {
        long long t_val = 1LL * t * (t + 1) / 2;
        // Pentagonal No
        for (int p = t; p > 1; p--) {
            long long p_val = 1LL * p * (3 * p - 1) / 2;
            if (p_val < t_val) break;

            if (p_val == t_val) {
                // Hexagonal No
                for (int h = p; h > 1; h--) {
                    long long h_val = 1LL * h * (2 * h - 1);
                    if (h_val < p_val) break;

                    if (t_val == p_val && t_val == h_val) {
                        cout << t << endl;
                        cout << t_val << endl;
                        return 0;
                    }
                }

                break;
            }
        }
    }   

    cout << "not" << endl;

return 0;
}