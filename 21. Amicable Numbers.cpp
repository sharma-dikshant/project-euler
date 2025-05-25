#include<bits/stdc++.h>
using namespace std;

int main () {

    int max_num = 10000;
    vector<int>arr(max_num + 1);

    for (int i = 2; i <= max_num; i++) {
        int d_sum = 0;
        for (int j = 1; j < i; j++) {
            if (i % j == 0) {
                d_sum += j;
            }
        }

        arr[i] = d_sum;
    }

    long long res = 0;
    vector<bool>visited(max_num + 1, false);
    for (int i = 2; i <= max_num; i++) {
        int a = i;
        int b = arr[a];

        if (b <= max_num && arr[b] == a && a != b && !visited[a] && !visited[b]) {
            res += (a + b);
            visited[a] = visited[b] = true;
        }
    }


    cout << res << endl;

    return 0;
}