#include<bits/stdc++.h>
using namespace std;

int main () {
    int range = 1000;
    int temp = range / 3;
    int no_of_multiple_of_3 = range == temp * 3 ? temp - 1 : temp;
    temp = range / 5;
    int no_of_multiple_of_5 = range == temp * 5 ? temp - 1 : temp;
    temp = range / 15;
    int no_of_multiple_of_15 = range == temp * 15 ? temp - 1 : temp;

    int sum_of_multiples_of_3 = 3 * no_of_multiple_of_3 * (1 + no_of_multiple_of_3) / 2;
    int sum_of_multiples_of_5 = 5 * no_of_multiple_of_5 * (1 + no_of_multiple_of_5) / 2;
    int sum_of_multiples_of_15 = 15 * no_of_multiple_of_15 * (1 + no_of_multiple_of_15) / 2;

    int res = sum_of_multiples_of_3 + sum_of_multiples_of_5 - sum_of_multiples_of_15;

    cout << res << endl;

    return 0;
}