#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n = 1;
    for (; n <= INT_MAX; n++) {
        int t_divisiors = 1;
        long long num = n * (n + 1) / 2;
        long long _num = num;
        // cout << num << endl;
        for (long long i = 2; i <= num; i++) {
            int cnt = 0;
            while (num % i == 0)
            {
                num /= i;
                cnt += 1;
            }

            t_divisiors *= (cnt + 1);
        }
        if (t_divisiors >= 500) {
            cout << _num << endl;
            cout << t_divisiors << endl;
            break;
        }
    }

    return 0;
}