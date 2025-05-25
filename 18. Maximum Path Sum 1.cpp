#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, vector<vector<int>>& grid) {
    if (i == grid.size()) return 0;

    int down  = grid[i][j] + solve(i + 1, j, grid);
    int right = grid[i][j] + solve(i + 1, j + 1, grid);

    return max(down, right);
    
}

int main () {

    int max_row = 15;
    vector<vector<int>>grid(max_row, vector<int>(max_row, 0));
    
    for (int i = 0; i < max_row; i++) {
        for (int j = 0; j <= i; j++) {
            cin>>grid[i][j];
        }
    }

    int res = solve(0, 0, grid);

    cout << res << endl;


    return 0;
}