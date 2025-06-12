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

            vector<int>arr(10, 0);
            unordered_set<char>st;
            for (int j = 0; j < curr.length(); j++) {
                st.insert(curr[j]);
                arr[(curr[j] - '0')]++;
                arr[(two[j] - '0')]++;
                arr[(three[j] - '0')]++;
                arr[(four[j] - '0')]++;
                arr[(five[j] - '0')]++;
                arr[(six[j] - '0')]++;
            }

            int unique = st.size();
            bool isValid = true;
            for (auto el: arr) {
                if (el % 6 != 0) {
                    isValid = false;
                    break;
                }
                if (el != 0) unique--;
            }
            
            if (isValid && unique != 0) {
                isValid = false;
            }

            if (isValid) {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}