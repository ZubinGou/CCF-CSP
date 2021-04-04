#include <iostream>
#include <regex>
using namespace std;
int n, m;
string p, r;
inline bool isStringDigit(const string &s)
{
    for (char c : s)
        if (c < '0' || c > '9')
            return 0;
    return 1;
}
int main()
{
    // freopen("201803-3.test", "r", stdin);
    cin >> n >> m;
    vector<pair<string, regex>> rules; //存储URL规则，映射为规则名->规则的正则表达式
    vector<pair<regex, string>> trans = {
        {regex("<int>"), "(\\d+)"},
        {regex("<str>"), "(\\w+)"},
        {regex("<path>"), "(.+)"}};
    while (n--)
    {
        cin >> p >> r;
        for (auto &i : trans)
            p = regex_replace(p, i.first, i.second); //将规则转换为对应的正则表达式
        rules.push_back({r, regex(p)});              //按输入顺序压入rules中
    }
    smatch result;
    while (m--)
    {
        cin >> p;
        int idx;
        for (idx = 0; idx < rules.size(); idx++)
        {
            auto &i = rules[idx];
            if (regex_match(p, result, i.second))
            {                                  //匹配成功
                printf("%s", i.first.c_str()); //输出规则名
                for (auto i = 1; i <= result.size(); ++i)
                { //遍历每一个匹配到的元组
                    p = result.str(i).c_str();
                    if (p != "" && isStringDigit(p)) //是整数
                        printf(" %d", stoi(p));      //输出转换后的整数，这里自动去除了前导0
                    else
                        printf(" %s", p.c_str()); //输出
                }
                puts(""); //换行
                break;
            }
        }
        if (idx == rules.size())
            puts("404"); //没有匹配到任何一个规则，输出404
    }
    return 0;
}