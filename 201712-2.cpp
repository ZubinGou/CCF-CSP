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
    int n, k;
    cin >> n >> k;
    list<int> res;
    for (int i = 0; i < n; i++) 
        res.push_back(i + 1);
    
    int i = 0;
    list<int>::iterator it = res.begin(), temp;
    while (res.size() > 1) {
        i++;
        if (i % 10 == k || i % k == 0) {
            temp = it;
            it--;
            res.erase(temp);
            it++;
        }
        else {
            it++;
        }
        it = (it == res.end()) ? res.begin() : it;
    }
    cout << res.front() << endl;
    return 0;
}