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
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end());
    int res = INT_MAX;
    for (int i = 1; i < n; i++)
        res = min(res, vec[i] - vec[i - 1]);
    cout << res;
    return 0;
}