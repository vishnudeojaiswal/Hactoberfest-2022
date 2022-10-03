#include <bits/stdc++.h>  
using namespace std;

vector<vector<int>>adj;

vector<int>subtree, ans;
int n;

void dfs1(int v, int p, int depth = 0){
    subtree[v] = 1;
    ans[1] += depth;
    for(auto i:adj[v]){
        if(i == p){
            continue;
        }
        dfs1(i, v, depth + 1);
        subtree[v] += subtree[i];
    }
    return;
}

void dfs2(int v, int p){
    for(auto i:adj[v]){
        if(i == p){
            continue;
        }
        ans[i] = ans[v] + n - 2 * subtree[i];
        dfs2(i, v);
    }
}

void solve(){
    cin>>n;
    adj.resize(n + 1);
    ans.resize(n + 1, 0);
    subtree.resize(n + 1, 0);
    for(int i = 1;i < n;i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    ans.erase(ans.begin());
    for(auto i:ans){
        cout<<i<<" ";
    }
}
int main()
{
    solve();
    return 0;
}