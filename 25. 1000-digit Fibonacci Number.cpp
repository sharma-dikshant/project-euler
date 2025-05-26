#include <bits/stdc++.h>
using namespace std;

void add (vector<int>& fir, vector<int>& sec, vector<int>& curr) {
    int carry = 0;
    int i = 0;

    while (i < curr.size()) {
        int a = i < fir.size() ? fir[i] : 0;
        int b = i < sec.size() ? sec[i] : 0;

        int temp = a + b + carry;
        curr[i] = temp % 10;
        carry = temp / 10;

        i++;
    }

    while (i < fir.size() || i < sec.size()) {
        int a = i < fir.size() ? fir[i] : 0;
        int b = i < sec.size() ? sec[i] : 0;

        int temp = a + b + carry;
        curr.push_back(temp % 10);
        carry = temp / 10;
        i++;
    }

    while (carry > 0) {
        curr.push_back(carry % 10);
        carry /= 10;
    }
    
    return;
}

int main () {
    vector<int>fir;
    vector<int>sec;
    vector<int>curr;

    fir.push_back(1);
    sec.push_back(2);
    curr.push_back(0);

    int pos = 2;

    while (curr.size() < 1000) {
        add(fir, sec, curr);
        fir = sec;
        sec = curr;
        pos++;
    }

    pos += 1;

    cout << pos << endl;
}