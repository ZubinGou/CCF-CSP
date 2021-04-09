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
typedef unordered_map<string, int> PL;

pair<string, int> parse_pl(string pl) {
    size_t found = pl.find(":");
    if (found == string::npos) return {pl, -1};
    else return {pl.substr(0, found), stoi(pl.substr(found + 1))};
}

void add_pl(PL& user, pair<string, int> p) {
    if (user.find(p.first) == user.end())
        user.insert(p);
    else
        user[p.first] = max(user[p.first], p.second);
}

int main() {
    ios::sync_with_stdio(false);
    // freopen("201612-3.test", "r", stdin);
    int p, r, u, q;
    cin >> p;
    string tmp;
    for (int i = 0; i < p; i++) {
        cin >> tmp;
    }

    unordered_map<string, PL> roles;
    string role_name;
    int pri_count;
    cin >> r;
    while (r--) {
        cin >> role_name >> pri_count;
        while (pri_count--) {
            cin >> tmp;
            add_pl(roles[role_name], parse_pl(tmp));
        }
    }
 
    unordered_map<string, PL> users;
    string user_name;
    int role_count;
    cin >> u;
    while (u--) {
        cin >> user_name;
        cin >> role_count;
        while (role_count--) {
            cin >> role_name;
            for (auto p : roles[role_name])
                add_pl(users[user_name], p);
        }
    }
 
    cin >> q;
    while (q--) {
        cin >> user_name;
        cin >> tmp;
        pair<string, int> pl = parse_pl(tmp);
        if (users.find(user_name) == users.end()) // user not exist
            cout << "false" << endl;
        else {
            PL user = users[user_name];
            if (user.find(pl.first) == user.end()) // no privilege
                cout << "false" << endl;
            else {
                int pl_level = user[pl.first];
                if (pl.second == -1 && pl_level > -1)
                    cout << pl_level << endl;
                else
                    cout << ((pl_level >= pl.second) ? "true" : "false") << endl;
            }
        }
    }
    return 0;
}