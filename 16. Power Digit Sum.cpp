#include <bits/stdc++.h>
using namespace std;

int main () {
    string res = "2";
    int carry = 0;
    int max_exp = 1000;

    for (int i = 2; i <= max_exp; i++) {
        string curr = res;
        for (int i = 0; i < res.length(); i++) {
            int sum = (curr[i] - '0') + (res[i] - '0') + carry;
            res[i] = sum % 10 + '0';
            carry = sum / 10;
        }

        if (carry > 0) {
            res += (carry + '0');
            carry = 0;
        }
    }

    int temp = 0;
    for (auto el: res) {
        temp += (el - '0');
    }

    reverse(res.begin(), res.end());
    cout << temp << endl;
  

    return 0;

}