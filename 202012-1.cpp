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
    int n, a, b;
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        res += a * b;
    }
    cout << max(0, res) << endl;
    return 0;
}