#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main () {
    // file
    ifstream inputFile("0022_names.txt");
    if (!inputFile) {
        cout << "Error! Opening File" << endl;
        return 1;
    }

    // reading data
    string data;
    if (!(inputFile >> data)) {
        cout << "Error! Reading File" << endl;
        return 1;
    }

    // creating arr
    vector<string>arr;
    stringstream ss(data);
    string temp;
    while (getline(ss, temp, ',')) {
        if (!temp.empty()) arr.push_back(temp);
    }

    //sort arr
    sort(arr.begin(), arr.end());
    
    // final calculation
    long long res = 0;

    for (int i = 0; i < arr.size(); i++) {
        int alpha_val = 0;
        for (auto& ch: arr[i]) {
            if (ch != '"') alpha_val += (ch - 'A' + 1);
        }

        res += 1LL * alpha_val * (i + 1);
    }

    cout << res << endl;

    return 0;
}