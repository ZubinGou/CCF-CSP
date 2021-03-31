// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <list>

using namespace std;
/*
1. 整体系数
2. 元素系数
3. 括号系数 - 嵌套
*/
unordered_map<string, int> res;

int get_digit(string& s) {
    if (s.empty() || !s.empty() && !isdigit(s[0])) return 1;
    int res = 0;
    while (!s.empty() && isdigit(s[0])) {
        res = res * 10 + s[0] - '0';
        s = s.substr(1);
    }
    return res;
}

void count_single(string s, int sign) {
    sign *= get_digit(s);
    while (!s.empty()) {
        // upper + lower
        if (isupper(s[0])) {
            string tmp;
            if (s.length() >= 2 && islower(s[1])) {
                tmp = s.substr(0, 2);
                s = s.substr(2);
            }
            else {
                tmp = s.substr(0, 1);
                s = s.substr(1);
            }
            int coeff = get_digit(s);
            if (res.find(tmp) == res.end()) res[tmp] = sign * coeff;
            else res[tmp] += sign * coeff;
        }
        else if (s[0] == '(') { // recursion for ()
            int bracket = 1, idx = 0;
            while (bracket) {
                idx++;
                if (s[idx] == '(') bracket++;
                else if (s[idx] == ')') bracket--;
            }
            string bracket_exp = s.substr(1, idx - 1);
            s = s.substr(idx + 1);
            int bracket_coeff = get_digit(s);
            count_single(bracket_exp, bracket_coeff * sign);
        }
    }
    return ;
}

void count_expr(string expr, int sign) {
    while (!expr.empty()) {
        size_t add = expr.find("+");
        add = (add == string::npos) ? expr.length() : add;
        count_single(expr.substr(0, add), sign);
        expr = (add == expr.length()) ? "" : expr.substr(add + 1);
    }
}

int main() {
    // freopen("201912-3.test", "r", stdin);
    int n;
    string formula;
    cin >> n;
    while (n--) {
        cin >> formula;
        res.clear();
        int eq = formula.find("=");
        count_expr(formula.substr(0, eq), 1);
        count_expr(formula.substr(eq + 1), -1);
        auto i = find_if(res.begin(), res.end(), [](const pair<string, int>& p) { return p.second != 0;});
        cout << (i == res.end() ? "Y" : "N") << endl;
    }
    return 0;
}