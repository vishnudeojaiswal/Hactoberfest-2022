#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<int> vis;
void dfs(int v, vector<int> &dis)
{
    vis[v] = 1;
    for (auto i : adj[v])
    {
        if (vis[i])
            continue;
        dis[i] = dis[v] + 1;
        dfs(i, dis);
    }
    return;
}
void solve()
{
    cin >> n;
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vis.clear();
    vis.resize(n + 1, 0);
    vector<int> dis(n + 1, 0);
    dfs(1, dis);
    int end1 = max_element(dis.begin(), dis.end()) - dis.begin();
    dis.clear();
    dis.resize(n + 1, 0);
    vis.clear();
    vis.resize(n + 1, 0);
    dfs(end1, dis);
    int end2 = max_element(dis.begin(), dis.end()) - dis.begin();
    vector<int> dis_1(n + 1, 0);
    vis.clear();
    vis.resize(n + 1, 0);
    dfs(end1, dis_1);
    vector<int> dis_2(n + 1, 0);
    vis.clear();
    vis.resize(n + 1, 0);
    dfs(end2, dis_2);
    for (int i = 1; i <= n; i++)
    {
        cout << max(dis_1[i], dis_2[i]) << " ";
    }
}
int main()
{
    solve();
    return 0;
}