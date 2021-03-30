// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <list>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <iomanip>

typedef unsigned int uint;

using namespace std;
/*
1. 特殊输入处理
2. 求出平均后判断是否与默认值或前一个值相同
3. 改变背景色
3. 每一行结束，不是默认则重置
4. 输出字符转义(一行)
设置背景色：\x1b[48;2;R;G;Bm
重置颜色：\x1b[0m
*/

string char2hex(char c, bool upper_case = true)
{
    stringstream ss;
    ss << std::hex << std::setfill('0') << std::setw(2) << (upper_case ? std::uppercase : std::nouppercase) << (int)c;
    string res = ss.str();
    return "\\x" + res;
}

int main()
{
    // freopen("201909-3.test2", "r", stdin);
    int m, n, p, q;
    cin >> m >> n >> p >> q;
    vector<vector<array<uint, 3>>> image(n);
    string rgb;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> rgb;
            if (rgb.length() == 2)
                rgb += string(5, rgb.back());
            else if (rgb.length() == 4)
                rgb = "#" + string(2, rgb[1]) + string(2, rgb[2]) + string(2, rgb[3]);
            image[i].push_back({0, 0, 0});
            for (int k = 0; k < 3; k++)
                image[i].back()[k] = stoi(rgb.substr(2 * k + 1, 2), 0, 16);
        }
    }
    array<int, 3> default_rgb = {0, 0, 0}, last_rbg = {0, 0, 0};
    string res = "";
    for (int i = 0; i < n / q; i++)
    {
        for (int j = 0; j < m / p; j++)
        {
            array<int, 3> cur_rgb = {0, 0, 0};
            for (int k = i * q; k < i * q + q; k++)
                for (int t = j * p; t < j * p + p; t++)
                    for (int r = 0; r < 3; r++)
                        cur_rgb[r] += image[k][t][r];
            for (int k = 0; k < 3; k++) {
                cur_rgb[k] /= p * q;
                // cout << cur_rgb[k] << " ";
            }
            if (cur_rgb == last_rbg)
                ;
            else if (cur_rgb == default_rgb)
                res += "\x1b[0m";
            else
                res += "\x1b[48;2;" + to_string(cur_rgb[0]) + ";" + to_string(cur_rgb[1]) + ";" + to_string(cur_rgb[2]) + "m";
            res += " ";
            last_rbg = cur_rgb;
        }
        if (last_rbg != default_rgb)
        {
            res += "\x1b[0m";
            last_rbg = default_rgb;
        }
        res += "\n";
    }

    // to ASCII
    string res_ascii = "";
    for (auto c : res)
        res_ascii += char2hex(c);
    // cout << res;
    cout << res_ascii;
    return 0;
}