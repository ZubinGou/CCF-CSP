// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <list>
#include <stack>
#include <algorithm>

using namespace std;

/*
1. 读入doc
2. 读入选择器，扫描doc，维护状态stack，逐个判断是否符合，符合则加入res
*/
struct Line
{
    int level;
    string tag;
    string id;
};

bool match(stack<string> selector, stack<pair<string, string>> st) {
    auto p = st.top(); st.pop();
    string sel = selector.top(); selector.pop();
    if (sel[0] != '#') { // tags are not case sensitive
        transform(sel.begin(), sel.end(), sel.begin(), ::tolower);
    }
    if (sel != p.first && sel != p.second) return false;

    while (!selector.empty() && !st.empty()) {
        sel = selector.top();
        if (sel[0] != '#') { // tags are not case sensitive
            transform(sel.begin(), sel.end(), sel.begin(), ::tolower);
        }
        while (!st.empty()) {
            auto p = st.top(); st.pop();
            if (sel == p.first || sel == p.second) {
                selector.pop(); 
                break;
            }
        }
    }
    return selector.empty();
}

vector<int> select(stack<string> selector, vector<Line> doc) {
    vector<int> res;
    stack<pair<string, string>> st;
    for (int i = 0; i < doc.size(); i++) {
        Line line = doc[i];
        while (st.size() > line.level) {
            st.pop();
            // cout << "pop" << " " << st.top().first << " " << st.top().second << endl;
        }
        st.push({line.tag, line.id});

        if (match(selector, st)) res.push_back(i + 1);
    }
    return res;
}

int main() {
    // freopen("201809-3.test", "r", stdin);
    int n, m;
    cin >> n >> m;
    
    vector<Line> doc;
    string line_str;
    getline(cin, line_str); // `/n` of last line
    for (int i = 0; i < n; i++) {
        getline(cin, line_str);
        size_t found = line_str.find_first_not_of(".");
        found = (found == string::npos) ? 0 : found;
        Line line;
        line.level = found / 2;
        line_str = line_str.substr(found);

        found  = line_str.find_first_of(" ");
        found = (found == string::npos) ? line_str.length() : found;
        line.tag = (line_str.substr(0, found));
        transform(line.tag.begin(), line.tag.end(), line.tag.begin(), ::tolower);
        line.id = line_str.substr(min(found + 1, line_str.length()));
        doc.push_back(line);
    }
    string str;
    for (int i = 0; i < m; i++) {
        getline(cin , str);
        stack<string> selector;
        string now;
        for (auto c : str) {
            if (c == ' ') {
                selector.push(now);
                now.clear();
            }
            else now.push_back(c);
        }
        selector.push(now);
        vector<int> res = select(selector, doc);
        cout << res.size();
        for (auto pos : res) 
            cout << " " << pos;
        cout << endl;
    }
    return 0;
}