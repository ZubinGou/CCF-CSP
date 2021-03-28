// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <list>

using namespace std;

unordered_map<string, int> func2id;

void init_func2id() {
    func2id["NOT"] = 0;
    func2id["AND"] = 1;
    func2id["OR"] = 2;
    func2id["XOR"] = 3;
    func2id["NAND"] = 4;
    func2id["NOR"] = 5;
}

struct node
{
    bool val;
    int func;
    vector<int> in;  // 输入信号作为输入
    vector<int> out; // 器件输出作为输入
};

vector<node> nodes(505);                              // 所有器件
vector<vector<bool> > input(10050, vector<bool>(505)); // 第i次运行的第j个输入

vector<int> indegree(505);                 // for topological sort
vector<vector<int> > adj(505, vector<int>()); // 邻接表

vector<int> topological_sort(int N)
{
    queue<int> Q;
    vector<int> res;
    for (int i = 1; i <= N; i++)
        if (!indegree[i])
            Q.push(i);
    while (!Q.empty())
    {
        int now = Q.front();
        Q.pop();
        res.push_back(now);
        int outdegree = adj[now].size();
        for (int i = 0; i < outdegree; i++)
        {
            int v = adj[now][i];
            if (!(--indegree[v]))
                Q.push(v);
        }
    }
    return res;
}

bool calculate(vector<bool> in, int func)
{
    if (func == 0)
        return !in[0];

    int ind = in.size();
    int res = in[0];
    if (func == 1)
    { // AND
        for (int i = 1; i < ind; i++)
            res &= in[i];
        return res;
    }
    if (func == 2)
    { // OR
        for (int i = 1; i < ind; i++)
            res |= in[i];
        return res;
    }
    if (func == 3)
    { // XOR
        for (int i = 1; i < ind; i++)
            res ^= in[i];
        return res;
    }
    if (func == 4)
    { // NAND
        for (int i = 1; i < ind; i++)
            res &= in[i];
        return !res;
    }
    if (func == 5)
    { // NOR
        for (int i = 1; i < ind; i++)
            res |= in[i];
        return !res;
    }
    return 0;
}

void run(vector<int> topo, int i)
{
    vector<bool> inp = input[i];
    vector<bool> inp_val;
    for (auto idx : topo)
    {
        inp_val.clear();
        // from "in"
        for (auto x : nodes[idx].in)
            inp_val.push_back(inp[x]);
        // from "out"
        for (auto x : nodes[idx].out)
            inp_val.push_back(nodes[x].val);
        nodes[idx].val = calculate(inp_val, nodes[idx].func);
    }
}

int main()
{
    init_func2id();
    int Q;
    int M, N;
    int S;
    string str;
    cin >> Q;
    while (Q--)
    {
        cin >> M >> N;
        // 初始化 TODO
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
            indegree[i] = 0;
            nodes[i].in.clear();
            nodes[i].out.clear();
        }
        // 输入器件
        for (int i = 1; i <= N; i++)
        {
            cin >> str;
            nodes[i].func = func2id[str];
            int k;
            cin >> k;
            for (int j = 0; j < k; j++)
            {
                cin >> str;
                int idx = stoi(str.substr(1));
                if (str[0] == 'I')
                    nodes[i].in.push_back(idx);
                else
                {
                    nodes[i].out.push_back(idx);
                    indegree[i]++;
                    adj[idx].push_back(i); // idx -> i
                }
            }
        }

        cin >> S;
        bool tmp;
        for (int i = 0; i < S; i++)
            for (int j = 1; j <= M; j++) {
                cin >> tmp;
                input[i][j] = tmp;
            }
        vector<int> topo = topological_sort(N);
        if (topo.size() < N)
            cout << "LOOP" << endl;

        for (int i = 0; i < S; i++)
        {
            int si;
            cin >> si;
            if (topo.size() == N)
                run(topo, i);
            int num;
            for (int j = 0; j < si; j++)
            {
                cin >> num;
                if (topo.size() == N) {
                    cout << nodes[num].val;
                    if (j < si - 1)
                        cout << " ";
                    else
                        cout << endl;
                }
            }
        }
    }
}