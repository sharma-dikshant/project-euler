#include<bits/stdc++.h>
using namespace std;

void multiple(vector<int>& arr, int x) {
    if (x == 1) return;
    int carry = 0;
    for (int i = 0; i < arr.size(); i++) {
        int curr = arr[i] * x + carry;
        arr[i] = curr % 10;
        carry = curr / 10;
    }

    while (carry > 0)
    {
        arr.push_back(carry % 10);
        carry /= 10;
    }
    
}

int main () {
    vector<int>res(1, 1);
    int fact_2 = 0;
    int fact_5 = 0;
    int max_num = 100;

    for (int i = 2; i <= max_num; i++) {
        int curr = i;
        while (curr % 2 == 0) {
            curr /= 2;
            fact_2++;
        }
        while (curr % 5 == 0) {
            curr /= 5;
            fact_5++;
        }
        multiple(res, curr);
    }

    int diff = fact_2 - fact_5;
    cout << diff << endl;
    
    while (diff--)
    {
        multiple(res, 2);
    }
    

    int f_res = 0;
    for (auto d: res) f_res += d;
    cout << f_res << endl;

    return 0;
}