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
    vector<int> input(n);
    for (int i = 0; i < n; i++)
        cin >> input[i];
    cout << (input[0] + input[1]) / 2 << " ";
    for (int i = 1; i < n - 1; i++)
        cout << (input[i - 1] + input[i] + input[i + 1]) / 3 << " ";
    cout << (input[n - 1] + input[n - 2]) / 2;
}