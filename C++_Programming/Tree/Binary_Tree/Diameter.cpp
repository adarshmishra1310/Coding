#include <bits/stdc++.h>
using namespace std;

// maximum distant node from any node will be one of the end of the diameter -> Tree distance 1
 
const int inf=1e9;
 
void dfs(vector<vector<int>> &adj,int s,vector<int> &depth,int p)
{
    for(auto &x:adj[s])
    {
        if(x!=p)
        {
            depth[x]=depth[s]+1;
            dfs(adj,x,depth,s);
        }
    }
}
 
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> depth(n,inf);
    depth[0]=0;
    dfs(adj,0,depth,-1);
    int mx=0,id=0;
    for(int i=0;i<n;i++)
    {
        if(mx<depth[i])
        {
            id=i;
            mx=depth[i];
        }
    }
    depth[id]=0;
    dfs(adj,id,depth,-1);
    mx=0;
    for(int i=0;i<n;i++) mx=max(mx,depth[i]);
    cout<<mx<<'\n';
    return 0;
}