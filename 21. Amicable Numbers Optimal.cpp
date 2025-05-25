#include<bits/stdc++.h>
using namespace std;

int main () {

    int max_num = 10000;
    vector<int>arr(max_num + 1, 0);

    for (int i = 1; i <= max_num / 2; i++) {
        for (int j = i*2; j <= max_num; j+=i) {
            arr[j] += i;
        }
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