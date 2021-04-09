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
/*
1. 解析区块，区块内部解析行内
2. 行内替换强调 `_` 奇偶分别为<em>, </em>
3. parse_url
*/

string parse_inline(string str) {
    string res;
    // deal with _
    int odd = 1;
    for (auto c : str) {
        if (c == '_') {
            res += (odd ? "<em>" : "</em>");
            odd = 1 - odd;
        }
        else res.push_back(c);
    }

    // deal with link
    string res_link;
    for (int i = 0; i < res.size(); i++) {
        if (res[i] == '[') {
            string text, link;
            i++;
            for (; i < res.size() && res[i] != ']'; i++) {
                text.push_back(res[i]);
            }       
            i += 2; // jump over ] (
            for (; i < res.size() && res[i] != ')'; i++) {
                link.push_back(res[i]);
            } 
            res_link += "<a href=\"" + link + "\">" + text + "</a>";
        }
        else res_link.push_back(res[i]);
    }
    return res_link;
}

string ltrim(string str) {
    size_t found = str.find_first_not_of(" ");
    return str.substr(found);
}

int main() {
    // freopen("201703-3.test", "r", stdin);
    ios::sync_with_stdio(false);
    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        if (line[0] == '#') {
            size_t found = line.find_first_not_of("#");
            string level = to_string(found);
            // while (line[found] == ' ') found++;
            string res = "<h" + level + ">" + ltrim(line.substr(found)) + "</h" + level + ">";
            res = parse_inline(res);
            cout << res << endl;
        }
        else if (line[0] == '*') {
            cout << "<ul>" << endl;
            cout << "<li>" << parse_inline(ltrim(line.substr(2))) << "</li>" << endl;
            while (getline(cin, line)) {
                if (line.empty()) break;
                else
                    cout << "<li>" << parse_inline(ltrim(line.substr(2))) << "</li>" << endl;
            }
            cout << "</ul>" << endl;
        }
        else {
            cout << "<p>" + parse_inline(line);
            while (getline(cin, line)) {
                if (line.empty())
                    break;
                else
                    cout << endl << parse_inline(line);
            }
            cout << "</p>" << endl;
        }
    }
    return 0;
}