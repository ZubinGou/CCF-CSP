// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <list>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    int m, y, y_hat, max_val, max_y, now_val;
    cin >> m;
    vector<pair<int, int>> inp(m);
    for (int i = 0; i < m; i++) {
        cin >> y >> y_hat;
        if (y_hat == 1) now_val++;
        inp[i] = {y, y_hat};
    }
    sort(inp.begin(), inp.end());
    max_y = inp[0].first;
    max_val = now_val;
    for (int i = 0; i < m;) {
        int old = inp[i].first;
        while (inp[i].first == old && i < m) {
            if (inp[i].second == 1)
                now_val--;
            else 
                now_val++;
            i++;
        }
        if (i != m && now_val >= max_val) {
            max_val = now_val;
            max_y = inp[i].first;
        }
    }
    // cout << max_y << " " << max_val << endl;
    cout << max_y << endl;
    return 0;
}