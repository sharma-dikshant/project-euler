#include <bits/stdc++.h>
#include <fstream>
using namespace std;

/*
    Tn = n * (n + 1) / 2
    therefore, eq => n^2 + n - 2Tn = 0
    for this is root must be integer D should be perfect sq. i.e. (1 + 4 * 2 * Tn) should be perfect sq
    and for positive root D > 1
*/

bool isValid(int n) {
    int D = 1 + 4 * 2 * n;
    int sqrt_D = sqrt(D);
    if (sqrt_D * sqrt_D != D || D <= 1) return false;

    return true;
}

int main()
{
    ifstream input("0042_words.txt");
    if (!input) {
        cout << "Error! opening file";
        return 1;
    }
    string data;
    input >> data;
    input.close();

    vector<string>words;
    stringstream ss(data);
    string temp;

    while (getline(ss, temp, '"')) {
       if (!temp.empty() && temp != ",") words.push_back(temp);
    }
    
    cout << words.size() << endl;

    int res = 0;
    for (int i = 0; i < words.size(); i++) {
        int val = 0;
        for (auto ch: words[i]) val += (ch - 'A' + 1);
        if (isValid(val)) res += 1;
    }

    cout << res << endl;



    return 0;
}