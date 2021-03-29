// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <list>
#include <climits>
// #incldue <

using namespace std;

int main() {    
    // freopen("201909-1.test", "r", stdin);
    int n, m;
    int remain = 0, max_idx = 1, max_val = INT_MIN;
    int now;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> now;
        int tmp;
        int tmp_sum = 0;
        for (int j = 0; j < m; j++){
            cin >> tmp;
            tmp_sum -= tmp;
        }
        if (tmp_sum > max_val) {
            max_val = tmp_sum;
            max_idx = i + 1;
        }
        remain += now - tmp_sum;
    }
    cout << remain << " " << max_idx << " " << max_val;
    return 0;
}