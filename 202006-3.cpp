// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <list>
#include <fstream>

using namespace std;


void trim(string& s) {
    s.erase(0, s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1, s.length());
}

int lineCount(string s, int w)
{
    int count = 0;
    while (s.size()) {
        count++;
        s = s.substr(min((int)s.length(), w));
        trim(s);
    }
    return max(1, count);
}

// int lineCount(string s, int w)
// {
//     for (int i = w; i < s.length(); i += w) {
//         while (s[i] == ' ')
//             s.erase(s.begin() + i);
//     }
//     return int(s.length() - 1) / w + 1;
// }
 
int main() {
    // freopen("202006-3.test2", "r", stdin);
    ios::sync_with_stdio(false);
    string line, str;
    int w, status = 0, count = -1, lastStatus = 0;
    cin >> w;
    while (getline(cin, line)) {
        lastStatus = status;
        if (line.find_last_not_of(" ") == string::npos) // blank space
            status = 0;
        else if (line.size() >= 2 && line.substr(0, 2) == "* ")
            status = 1;
        else if ((status == 1 || status == 2) && line.substr(0, 2) == "  ") // rest of item
            status = 2;
        else // par
            status = 3;
        
        if ((status != 0 && lastStatus == 0) || ((lastStatus == 1 || lastStatus == 2) && status == 3) || (lastStatus == 3 && status == 1))
            count++;

        if ((lastStatus == 1 || lastStatus == 2) && status != 2)
            count += lineCount(str, w - 3);
        else if (lastStatus == 3 && status != lastStatus)
            count += lineCount(str, w);
        
        // deal with line str
        if (status == 1) {
            line = line.substr(2);
            trim(line);
            str = line;
        }
        else if (status == 2) {
            line = line.substr(2);
            trim(line);
            if (!str.empty())
                line = " " + line;
            str += line;
        }
        else if (status == 3) {
            if (lastStatus != 3)
                str = "";
            trim(line);
            if (!str.empty())
                line = " " + line;
            str += line;
        }
        // cout << "count: " << count << " status: " << status << " \"" << line << "\"" << endl;
    }
    // reamin str
    if (status == 1 || status == 2)
        count += lineCount(str, w - 3);
    else if (status == 3)
        count += lineCount(str, w);
    cout << count;
    return 0;
}