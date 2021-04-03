// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <list>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int status, score = 2, res = 0;
    cin >> status;
    if (status == 2) {
        score = 2;
        res += score;
    }
    else if (status == 1) {
        score = 1;
        res += score;
    }
    while (cin >> status) {
        if (status == 0)
            break;
        else if (status == 1) {
            score = 1;
        }
        else {
            score = (score == 1) ? 2 : score + 2;
        }
        res += score;
    }
    cout << res;
}