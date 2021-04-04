// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <list>

using namespace std;

/*
1. 分别读入，逐条匹配
2. 首先匹配path -> 不为空、非斜杠结尾
3. 匹配相同
4. 匹配int -> 数字直到斜杠
5. 匹配str，直到斜杠
5. 用字符数组记录参数，返回t/f，参数传引用，去掉前导0
*/

bool is_str(char c) {
    return isalnum(c) || c == '-' || c == '_' || c == '.';
}

bool match(string rule, string url, vector<string>& params) {
    int i, j;
    for (i = 0, j = 0; i < rule.length(), j < url.length(); i++, j++) {
        if (rule[i] == url[j] && rule[i] != '<');
        else if (i == rule.length() - 6 && rule.substr(i, 6) == "<path>") {
            if (j < url.length() && url.back() != '/') {
                params.push_back(url.substr(i));
                return true;
            }
            else return false;
        }
        else if (i <= rule.length() - 5 && rule.substr(i, 5) == "<int>") {
            string itg;
            int jj;
            for (jj = j; jj < url.size() && url[jj] != '/'; jj++) {
                if ('0' <= url[jj] && url[jj] <= '9') {
                    itg += url.substr(jj, 1);
                }
                else return false;
            }
            if (j != jj) {
                // delete prefix 0
                int k;
                for (k = 0; k < itg.length() - 1; k++)
                    if (itg[k] != '0') break;
                params.push_back(itg.substr(k));
                i += 4;
                j = jj - 1;
            }
            else return false;
            // cout << "int then " << rule.substr(i) << " " << url.substr(j) << endl;
        }
        else if (i <= rule.length() - 5 && rule.substr(i, 5) == "<str>") {
            string str;
            int jj;
            for (jj = j; jj < url.size() && url[jj] != '/'; jj++) {
                if (is_str(url[jj]))
                    str += url.substr(jj, 1);
                else return false;
            }
            if (j != jj) {
                params.push_back(str);
                i += 4;
                j = jj - 1;
            }
            else return false;
            // cout << "str then " << rule.substr(i) << " " << url.substr(j) << endl;
        }
        else
            return false;
    }
    if (i == rule.length() && j == url.length()) return true;
    else return false;
}

int main() {
    // freopen("201803-3.test", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<string> rules(n);
    vector<string> rules_name(n);
    for (int i = 0; i < n; i++) {
        cin >> rules[i];
        cin >> rules_name[i];
    }

    string url;
    for (int i = 0; i < m; i++) {
        cin >> url;
        int j;
        vector<string> params;
        for (j = 0; j < n; j++) {
            params.clear();
            if (match(rules[j], url, params)) {
                cout << rules_name[j];
                for (auto x : params)
                    cout << " " << x;
                cout << endl;
                break;
            }
        }
        if (j == n)
            cout << "404" << endl;
    }
    return 0;
}