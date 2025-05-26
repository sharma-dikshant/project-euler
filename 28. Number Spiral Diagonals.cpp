#include<bits/stdc++.h>
using namespace std;

int main() {
    int max_size = 1001;
    // cout << sqrt(max_size) << endl;
    vector<vector<int>>grid(max_size, vector<int>(max_size, 0));
    int i = max_size / 2 , j = max_size / 2;

    int steps = 1;
    int curr = 1;
    grid[i][j] = curr++;
    while (curr <= max_size * max_size) {
        for (int k = 1; k <= steps && curr <= max_size * max_size; k++) {
            j += 1;
            grid[i][j] = curr;
            curr++;
        }
        for (int k = 1; k <= steps && curr <= max_size * max_size; k++) {
            i += 1;
            grid[i][j] = curr;
            curr++;
        }

        steps++;

        for (int k = 1; k <= steps && curr <= max_size * max_size; k++) {
            j -= 1;
            grid[i][j] = curr;
            curr++;
        }
        for (int k = 1; k <= steps && curr <= max_size * max_size; k++) {
            i -= 1;
            grid[i][j] = curr;
            curr++;
        }

       steps++;
    }

    long long res = -1;
    i = 0;
    for (; i < max_size; i++) {
        res += grid[i][i];
        res += grid[i][max_size - i - 1];
    }
    
    cout << res << endl;


    return 0;
}