// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    // freopen("201803-2.test2", "r", stdin);
    int n, L, t;
    cin >> n >> L >> t;
    int begin, end;
    vector<int> res;
    vector<pair<int, int>> order;
    t %= 2 * L;
    for (int i = 0; i < n; i++) {
        cin >> begin;
        end = (begin + t) % (2 * L);
        end = (end > L) ? (2 * L - end) : end;
        res.push_back(end);
        order.push_back({begin, i});
    }
    sort(res.begin(), res.end());
    sort(order.begin(), order.end());

    vector<int> orderd_res(n);
    for (int i = 0; i < n; i++)
        orderd_res[order[i].second] = res[i];
    
    cout << orderd_res[0];
    for (int i = 1; i < n; i++)
        cout << " " << orderd_res[i];
}