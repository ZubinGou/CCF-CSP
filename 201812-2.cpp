// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <list>

using namespace std;
enum COLOR {ROAD, RED, YELLOW, GREEN};

int main() {
    // freopen("201812-1.test", "r", stdin);
    ios::sync_with_stdio(false);
    int r, y, g;
    int n;
    cin >> r >> y >> g;
    cin >> n;
    int rgy = r + y + g;
    int type, period;
    long long res = 0;
    for (int i = 0; i < n; i++) {
        cin >> type >> period;
        if (type == ROAD) {
            res += period;
            continue;
        }
        if (type == RED)
            period = (r - period);
        else if (type == GREEN)
            period = (r + g - period);
        else if (type == YELLOW)
            period = (rgy - period);
        period = (period + res % rgy) % rgy;
        
        if (period >= r + g)
            res += r + rgy - period;
        else if (period < r)
            res += r - period;
        // cout << res << endl;
    }
    cout << res;
    return 0;
}