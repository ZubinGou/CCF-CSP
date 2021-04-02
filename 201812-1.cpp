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
    int r, y, g;
    int n;
    cin >> r >> y >> g;
    cin >> n;
    int type, period, res = 0;
    for (int i = 0; i < n; i++) {
        cin >> type >> period;
        if (type == ROAD || type == RED)
            res += period;
        else if (type == YELLOW)
            res += period + r;
    }
    cout << res;
    return 0;
}