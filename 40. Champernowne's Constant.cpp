#include<bits/stdc++.h>
using namespace std;

int main() {

    string d = "";
    int limit  = 1000000; // 1Million
    int i = 1;
    while(d.length() < limit) {
        d += to_string(i++);
    }

    int res = 1;
    i = 1;

    while (i < limit) {
        res *= (d[i - 1] - '0');
        i *= 10;
    }

    cout << res << endl;

return 0;
}