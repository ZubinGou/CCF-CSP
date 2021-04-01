// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <list>

using namespace std;

const int block_size = 4;
/*
1. 求出块在哪个盘，第几块
2. 未丢失则直接读取
3. 丢失则判断是否只差一块，是则采用校验码和其他阵列数据计算，否则输出‘-’
*/

int main() {
    // freopen("201903-3.test2", "r", stdin);
    ios::sync_with_stdio(false);
    int n, strip_size, l, m, block;
    cin >> n >> strip_size >> l;
    vector<string> raid(n, "");
    int disk;
    int disk_count = 0;
    int disk_size = 0;
    for (int i = 0; i < l; i++) {
        cin >> disk;
        cin >> raid[disk];
        disk_count++;
        disk_size = raid[disk].length();
    }
    int disk_layer_count = disk_size / 8 / strip_size;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> block;
        int layer = block / (strip_size * (n - 1));
        int idx = block % (strip_size * (n - 1));
        int pair = n - layer % n - 1;
        int disk = (pair + 1 + idx / strip_size) % n;
        int disk_block = layer * strip_size + idx % strip_size;
        // cout << layer << " " << idx << " " << pair << " " << disk << " " << disk_block << endl;
        if (layer < disk_layer_count && !raid[disk].empty()) {
            cout << raid[disk].substr(disk_block * 8, 8) << endl;
        }
        else if (layer >= disk_layer_count || disk_count < n - 1)
            cout << "-" << endl;
        else { // xor of all disks != disk
            int res = 0, hex;
            string temp;
            for (int j = 0; j < n; j++) {
                if (j == disk) continue;
                temp = raid[j].substr(disk_block * 8, 8);
                sscanf(temp.c_str(), "%x", &hex);
                res ^= hex;
            }
            printf("%08X\n", res);
        }
    }
    return 0;
}