#include <bits/stdc++.h>
using namespace std;

int main () {
    long long input_no = 600851475143;
    // long long input_no = 144;
    int largest_prime_factor = 1;

    for (long long i = 2; i <= input_no; i++) {
        if (input_no % i == 0) {
            largest_prime_factor = i;
        }

        while (input_no % i == 0) {
            input_no /= i;
        }

        if (input_no == 1) break;
    }

    cout << largest_prime_factor << endl;
}