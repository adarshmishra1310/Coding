#include <bits/stdc++.h>
using namespace std;
#define int long long

// Diameter of Tree -> first find the farthest node from the root then find farthest node from that node.
// https://codeforces.com/blog/entry/101271

void dfs(vector<vector<int>> &adj,int s,vector<bool> &vis,vector<int> &depth)
{
    vis[s]=true;
    for(auto &x:adj[s])
    {
        if(!vis[x])
        {
            depth[x]=depth[s]+1;
            // cout<<x<<' '<<depth[x]<<'\n';
            dfs(adj,x,vis,depth);
        }
    }
}

void runCase(int &testcase)
{
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        --x;--y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool> vis(n,0);
    vector<int> depth(n,0);
    dfs(adj,0,vis,depth); // Find the farthest node from root
    int a=0,mx=0;
    for(int i=0;i<n;i++)
    {
        if(mx<depth[i])
        {
            a=i;
            mx=depth[i];
        }
    }
    for(int i=0;i<n;i++) vis[i]=false;
    for(int i=0;i<n;i++) depth[i]=0;
    dfs(adj,a,vis,depth); // Find the farthest node from the farthest node from root
    mx=0;
    for(int i=0;i<n;i++)
    {
        mx=max(mx,depth[i]);
    }
    cout<<mx<<'\n';

}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for (int i = 1; i <= tests; i++)
    {
        // cout << "Case #" << i << ": \n";
        runCase(i);
    }
    return 0;
}