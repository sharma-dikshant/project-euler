#include <bits/stdc++.h>
using namespace std;

long long solve(int i, int j, vector<vector<long long>>& grid) {
    if (i == grid.size() || j == grid.size()) return 0;
    if (i == grid.size() - 1 && j == grid.size() - 1) return 1;

    if (grid[i][j] != -1) return grid[i][j];

    //left
    long long right = solve(i, j + 1, grid);
    //right
    long long down = solve(i + 1, j, grid);

    return grid[i][j] = down + right;
}

int main () {
    int grid_size = 21;
    vector<vector<long long>>grid(grid_size, vector<long long>(grid_size, -1));
    long long ans = solve(0, 0, grid);

    cout << ans << endl;
}