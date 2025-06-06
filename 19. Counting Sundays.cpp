#include <bits/stdc++.h>
using namespace std;

bool isLeap(int year) {
    if (year % 4 != 0) return false;
    if (year % 100 == 0 && year % 400 != 0) return false;

    return true;
}

int main() {

    int res = 0; 
    vector <int> m_day = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


    int curr = 2; // Tuesday on 1 Jan 1901
    for (int year = 1901; year <= 2000; year++) {
        for (int m = 0; m < m_day.size(); m++) {
            if (curr == 0) { //  Sunday
                res += 1;
            }

            int t_days = m_day[m];
            if (m == 1 && isLeap(year)) { // febraury 
                t_days += 1;
            }

            curr = curr + (t_days % 7);
            curr %= 7;
        }
    }

    cout << res << endl;

    return 0;
}

