#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isValid (const string& str) {
    int even = 0;
    int five = 0;

    for (auto& ch: str) {
        if (ch == '5') five++;

        if (ch == '0') {
            even++; five++;
        }
        else if ((ch - '0') % 2 == 0) even++;
    }

    if (even == 0 || five == 0) return false;
    return true;
}

int main () {

    for (int i = 10; ; i++) {
        string curr = to_string(i);
        if (isValid(curr)) {
            string two   = to_string(2 * i);
            string three = to_string(3 * i);
            string four  = to_string(4 * i);
            string five  = to_string(5 * i);
            string six   = to_string(6 * i);

            if (two.length() + three.length() + four.length() + five.length() + six.length() != 5 * curr.length()) continue;

            sort(curr.begin(), curr.end());
            sort(two.begin(), two.end());
            sort(three.begin(), three.end());
            sort(four.begin(), four.end());
            sort(five.begin(), five.end());
            sort(six.begin(), six.end());

            if (curr != two || curr != three || curr != four || curr != five || curr != six) continue;

            cout << i << endl;
            break;
        }
    }

    return 0;
}