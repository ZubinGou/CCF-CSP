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
    // freopen("201909-2.test", "r", stdin);
    int n, m;
    int remain = 0, fall_count = 0, fall_3_count = 0;
    int now;
    cin >> n;
    vector<bool> has_fall(n, false);
    for (int i = 0; i < n; i++) {
        cin >> m;
        cin >> now;
        int tmp;
        for (int j = 1; j < m; j++){
            cin >> tmp;
            if (tmp > 0) {
                if (tmp < now)
                    has_fall[i] = true;
                now = tmp;
            }
            else
                now += tmp;
        }
        remain += now;
    }
    for (auto b : has_fall)
        if (b) fall_count++;
    for (int i = 0; i < n; i++) {
        if (has_fall[i] && has_fall[(i + 1) % n] && has_fall[(i + 2) % n])
            fall_3_count++;
    }
    cout << remain << " " << fall_count << " " << fall_3_count;
    return 0;
}