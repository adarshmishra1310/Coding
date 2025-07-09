#include <bits/stdc++.h>
using namespace std;

// CSES -> Company queries 1 and Company queries 2
// Problem -> there is a tree rooted as 0, answer q queries
// Given v and k, find the k-th ancestor of node v

// Logic of binary lifting
/*
    1. Any k can be represented as sum of powers of two
    2. Store for every node 2^jth ancestor
    3. Ex - 19 -> 16 + 2 + 1
    4. Make 16 vetex jump from v, then 2 jump from that node and then 1 jump from that node
*/

// Time complexity -> Preprocessing = O(nlog(n)), Query = O(log(n))
// Space complexity -> O(nlog(n))

vector<vector<int>> binaryLifting(vector<int> &par,int n)
{
    int LOG = log2(n);
    vector<vector<int>> up(n,vector<int>(LOG+1,-1));
    for(int j=0;j<LOG+1;j++)
    {
        for(int i=0;i<n;i++)
        {
            if(j==0) up[i][0]=par[i];
            else
            {
                if(up[i][j-1]==-1) up[i][j]=-1;
                else up[i][j]=up[up[i][j-1]][j-1];
            }
        }
    }
    return up;
}

int kthAncestor(vector<vector<int>> &up,int v,int k)
{
    int LOG=up[0].size()-1;
    for(int i=0;i<=LOG && v>=0;i++)
    {
        if(k & (1<<i)) v=up[v][i];
    }
    return v;
}

int lca(vector<vector<int>> &up,vector<int> &depth,int x,int y)
{
    if(depth[x]>depth[y]) x=kthAncestor(up,x,depth[x]-depth[y]);
    else if(depth[y]>depth[x]) y=kthAncestor(up,y,depth[y]-depth[x]);
    int LOG=up[0].size()-1;
    for(int i=LOG;i>=0;i--)
    {
        if(up[x][i]!=up[y][i]) x=up[x][i],y=up[y][i];
    }
    if(x==y) return x;
    return up[x][0];
}

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
    int n,q;
    cin>>n>>q;
    vector<vector<int>> adj(n);
    vector<int> par(n,-1);
    for(int i=1;i<n;i++)
    {
        int x;
        cin>>x;
        x--;
        adj[i].push_back(x);
        adj[x].push_back(i);
        par[i]=x;
    }
    vector<vector<int>> up=binaryLifting(par,n);
    vector<int> depth(n,0);
    dfs(adj,0,depth,-1);  
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        cout<<lca(up,depth,x,y)+1<<'\n';
    }
    return 0;
}