#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<pair<int, int>> st;
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        st.insert({x, y});
    }
    vector<int> res(5, 0);
    for (auto p : st) {
        x = p.first, y = p.second;
        if (st.find({x - 1, y}) != st.end() && st.find({x + 1, y}) != st.end() &&
            st.find({x, y - 1}) != st.end() && st.find({x, y + 1}) != st.end()) {
            int count = 0;
            if (st.find({x - 1, y - 1}) != st.end()) count++;
            if (st.find({x + 1, y + 1}) != st.end()) count++;
            if (st.find({x - 1, y + 1}) != st.end()) count++;
            if (st.find({x + 1, y - 1}) != st.end()) count++;
            res[count]++;
        }
    }
    for (auto x : res)
        cout << x << endl;
}