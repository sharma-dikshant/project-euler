#include<bits/stdc++.h>
using namespace std;

int main() {

    /*
    4 => 1 1 2
    5 => 1 1 3  1 2 2
    6 => 2 2 2  1 2 3  1 1 4
    7 => 2 2 3  1 2 4  1 1 5 
    8 => 2 2 4  1 3 4  1 2 5  1 1 6
    9 => 1 1 7  1 2 6  1 3 5  2 2 5
   10 => 1 1 8  1 2 7  1 3 6  1 4 5  2 2 6  2 3 5
    */    

    int max_peri = 10000;
    int res = 0;
    int sol = 0;
    for (int p = 10; p <= max_peri; p++) {
        int curr_p = 0;
        for (int a = 1; a <= max_peri / 3; a++) {
            for (int b = a; b <= (max_peri - a) / 2; b++) {
                int c = p - (a + b);
                if (c < a || c < b) break;
                if (a + b > c && a + c > b && b + c > a && a * a + b * b == c * c) {
                    curr_p += 1;
                } 
            }
        }
        if (curr_p > sol) {
            sol = curr_p;
            res = p;
        }
    }

    cout << res << endl;

    return 0;
}