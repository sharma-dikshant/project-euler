#include<bits/stdc++.h>
using namespace std;

int main () {
    vector<string>ones(10 ,"");
    vector<string>teens(20, "");
    vector<string>tens(10, "");
    ones[1] = "one";
    ones[2] = "two";
    ones[3] = "three";
    ones[4] = "four";
    ones[5] = "five";
    ones[6] = "six";
    ones[7] = "seven"; 
    ones[8] = "eight"; 
    ones[9] = "nine"; 
    
    teens[11] = "eleven";
    teens[12] = "twelve";
    teens[13] = "thirteen";
    teens[14] = "fourteen";     
    teens[15] = "fifteen";
    teens[16] = "sixteen";
    teens[17] = "seventeen";
    teens[18] = "eighteen";
    teens[19] = "nineteen";  

    tens[1] = "ten";
    tens[2] = "twenty";
    tens[3] = "thirty";
    tens[4] = "forty";     
    tens[5] = "fifty";
    tens[6] = "sixty";
    tens[7] = "seventy";
    tens[8] = "eighty";
    tens[9] = "ninety";

    // 123

    int res = 0;
    for (int i = 1; i < 1000; i++) {
        if (i < 10) {
            res += ones[i].length();
        } else if (i == 10) {
            res += tens[1].length();
        } else if (i >= 11 && i <= 19) {
            res += teens[i].length();
        } else {
            int tens_val = i % 100;
            int hund_val = i / 100;

            
            if (tens_val > 10 && tens_val < 20) {
                res += teens[tens_val].length();
            } else {
                int one_val = tens_val % 10;
                int _tens_val = tens_val / 10;

                if (one_val > 0) {
                    res += ones[one_val].length();
                }

                if (_tens_val > 0) {
                    res += tens[_tens_val].length();
                }
            }

            if (hund_val > 0) {
                // two hundred and thirteen
                res += 7; // "hundred";
                res += ones[hund_val].length();
                if (tens_val != 0) res += 3; // and
            }
        }
    }

    res += 11; // one thousand
    
    cout << res << endl;

    return 0;
    
}