// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <unordered_map>
#include <queue>
#include <list>
#include <cmath>
#include <algorithm>

using namespace std;
/*
1. 输入解析：标准型、省略后缀型、省略长度型（均合法）
2. 计算IP前缀数目最少的前缀列表
    - 排序
    - 从小到大合并（消灭子集）
    - 合并同级
3. 排序，按照IP从小到大、前缀从小到大输出
*/

/*
总结：
1. 位运算：注意优先级，都加上括号
2. 第一次过程中，长数组 erase 会导致超时
*/

struct IP {
    long long prefix;
    int len;
    bool operator<(IP b) {
        return prefix < b.prefix || (prefix == b.prefix && len <= b.len);
    }
};

// bool cmp(const IP a, const IP b) {
//     return a.prefix < b.prefix || (a.prefix == b.prefix && a.len <= b.len);
// }

string ip2str(IP ip) {
    string res = to_string(ip.prefix % 256);
    long long pre = ip.prefix / 256;
    int cnt = 3;
    while (cnt--) {
        int seg = pre % 256;
        res = to_string(pre % 256) + "." + res;
        pre /= 256;
    }
    res += "/" + to_string(ip.len);
    return res;
}

bool is_subset(const IP a, const IP b) { // b is subset of a ?
    int t = 32 - a.len;
    return b.len >= a.len && (a.prefix >> t) == (b.prefix >> t);
}

bool is_valid(const IP a) {
    int mask = (1 << (32 - a.len)) - 1;
    return a.len >= 0 && a.len <= 32 && (a.prefix & mask) == 0;
}

// bool is_valid(const IP a) {
//     int t = 32 - a.len;
//     return a.len >= 0 && a.len <= 32 && ((a.prefix >> t) << t) == a.prefix;
// }

bool check_merge(const IP a, const IP b) {
    if (a.len != b.len || a.len <= 0) return false;
    int t = 32 - a.len;
    if ((a.prefix >> (t + 1)) != (b.prefix >> (t + 1))) return false;
    return ((a.prefix >> t) & 1) == 0 && ((b.prefix >> t) & 1) == 1;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<IP> ips(n);
    string ip_str;

    // step0. input
    for (int i = 0; i < n; i++) {
        long long tmp[4], now = 0;
        memset(tmp, 0, sizeof(tmp));
        int k = 0, dot = 0, slash = 0;
        cin >> ip_str;
        for (int j = 0; j < ip_str.length(); j++) {
            if (ip_str[j] == '/') {tmp[k++] = now; now = 0; slash++; continue;};
            if (ip_str[j] == '.') {tmp[k++] = now; now = 0; dot++; continue;};
            now = now * 10 + ip_str[j] - '0';
        }
        if (slash)
            ips[i].len = now;
        else {
            ips[i].len = (dot + 1) * 8;
            tmp[k] = now;
        }
        for (int k = 0; k < 4; k++)
            ips[i].prefix += tmp[k] * pow(256, 3 - k);
    }

    // step1. sort
    // sort(ips.begin(), ips.end(), cmp); // method 1. cmp
    sort(ips.begin(), ips.end());        // method 2. reload <

    // step2. merge neighbour
    vector<IP> ips_tmp;
    for (int i = 0; i < n; i++) {
        int j = i + 1;
        while (j < n && is_subset(ips[i], ips[j])) j++;
        ips_tmp.push_back(ips[i]);
        i = j - 1;
    }
    ips.clear();
    ips = ips_tmp;

    // step3. merge peer method 1
    // i = 0, j = 1;
    // while (j > 0 && j < ips.size()) {
    //     IP ip_new = ips[i];
    //     ip_new.len--;
    //     if (ips[i].len == ips[j].len && is_valid(ip_new) && is_subset(ip_new, ips[i]) && is_subset(ip_new, ips[j])) {
    //         ips.erase(ips.begin() + i);
    //         ips.erase(ips.begin() + i);
    //         ips.insert(ips.begin() + i, ip_new);
    //         if (i > 0) i--, j--;
    //     }
    //     else {
    //         i++;
    //         j++;
    //     }
    // }

    // step3. method 2
    for (auto it = ips.begin(); it != ips.end() - 1; it++) {
        IP a = *it, b = *(it + 1);
        if (check_merge(*it, *(it + 1))) {
            ips.erase(it + 1);
            (*it).len--;
            it = (it == ips.begin()) ? it - 1 : it - 2;
        }
    }

    for (auto ip : ips) {
        cout << ip2str(ip) << endl;
    }
    return 0;
}