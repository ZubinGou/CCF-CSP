// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <queue>
#include <list>
#include <climits>
#include <algorithm>
#include <cassert>

using namespace std;
/*
1. recurrence input 
2. parse dict, escape character
3. return type: STRING, OBJECT, NOTEXIST
*/

enum JSON_TYPE {OBJECT, STRING, NOTEXIST};

struct Json {
    int type;
    string str;
    // unordered_map<string, Json> m; // TODO hash map
    map<string, Json> m;
};

string parse_str() {
    string res;
    char c;
    while ((c = getchar()) != '"') {
        if (c == '\\') { // escape character
            c = getchar();
        }
        res.push_back(c);
    }
    return res;
}

Json parse() {
    Json res;
    res.type = OBJECT;
    char c;
    while ((c = getchar()) != '}') {
        if (c == ' ' || c == '\n' || c == ',') continue;
        if (c == '"') {
            string key = parse_str();
            while ((c = getchar()) != ':');
            while (c = getchar()) {
                if (c == '"') {
                    Json val;
                    val.type = STRING;
                    val.str = parse_str();
                    res.m[key] = val;
                    break;
                }
                else if (c == '{') {
                    res.m[key] = parse();
                    break;
                }
            }
        }
    }
    return res;
}

Json query(Json json, string str) {
    Json null_res;
    null_res.type = NOTEXIST;

    size_t found = str.find(".");
    if (found == string::npos) {
        if (json.m.find(str) == json.m.end()) return null_res;
        return json.m[str];
    }
    else {
        if (json.m.find(str.substr(0, found)) == json.m.end()) return null_res;
        return query(json.m[str.substr(0, found)], str.substr(found + 1));
    }
}

int main() {
    // freopen("201709-3.test", "r", stdin);
    int n, m;
    cin >> n >> m;
    char c;
    getchar();
    c = getchar();
    assert(c == '{');
    Json root = parse();

    string query_str;
    for (int i = 0; i < m; i++) {
        cin >> query_str;
        Json res = query(root, query_str);
        if (res.type == NOTEXIST)
            cout << "NOTEXIST" << endl;
        else if (res.type == STRING) { 
            cout << "STRING " << res.str << endl;
        }
        else {
            cout << "OBJECT" << endl;
        }
    }
    return 0;
}