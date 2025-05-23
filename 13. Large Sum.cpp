#include <bits/stdc++.h>
#include<fstream>
using namespace std;

int main () {
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr<< "could not open file"<<endl;
        return 1;
    }


    int t_no = 100;
    int str_size = 50;
    vector<string>input(t_no);
    string res = "";

    for (int i = 0; i < t_no; i++) {
        inputFile >> input[i];
    }
    inputFile.close();
    // for (int i = 0; i < t_no; i++) {
    //     cin >> input[i];
    // }

    for (int i = 0; i < str_size; i++) res += '0';

    int r_carry = 0;
    for (auto el: input) {
        int carry = 0;
        for (int i = str_size - 1; i >= 0; i--) {
            int curr = (res[i] - '0') + (el[i] - '0') + carry;

            res[i] = (curr % 10) + '0';
            carry = curr / 10;
        }

        r_carry += carry;
    }

    if (r_carry > 0) {
        reverse(res.begin(), res.end());
        res.append(to_string(r_carry));
        reverse(res.begin(), res.end());
    }
    for (int i = 0; i < str_size; i++) cout << res[i];
    cout << endl;

    return 0;

}