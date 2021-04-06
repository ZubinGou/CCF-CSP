// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <list>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> period(n);
    for (int i = 0; i < n; i++)
        cin >> period[i].first >> period[i].second;
    int res = 0;
    int j = 0, s, t;
    for (int i = 0; i < n; i++) {
        cin >> s >> t;
        for (; j < n; j++) {
            if (t <= period[j].first) break;
            else if (s >= period[j].second) continue;
            else {
                res += min(t, period[j].second) - max(s, period[j].first);
                if (t > period[j].second) s = period[j].second;
                else break;
            }
        }
        if (j == n) break;
    }
    cout << res;
}