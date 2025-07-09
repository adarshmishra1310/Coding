#include <bits/stdc++.h>
using namespace std;
#define int long long
+
const int inf = INT64_MAX; 

// Bellman Ford
// 1. Relax every edge n-1 times because a single shortest path from src to destination can have atmost n-1 edges
// 2. Doesn't work in case of negative weight cycle, but it can detect that.
// 3. If after performing relaxation n-1 times, edges are still getting relaxed then there is a -ve edge cycle

// To understand, can watch abdul bari video 

// CSES -> High score
// In this problem we have to calculate maximum weight from going 0 to n-1
// if there are positive weight cycle and it is reachable from 0, and n-1 is reachable from this cycle then only the weight for going 0 to n-1 will be infinity
// We can precompute reachable array using dfs from each vertex to n-1, and from any positive cycle we can check if its distance from 0 is not -inf.
// if n-1 is reachable from a positive cycle and shortest distance from 0 to any of the vertex in the cycle is not -infinity then answer will be infinity
// else positive weight cycle(if there) will not affect the distance between 0 to n-1; 

// can watch cses solution, its good and simple

void bellmanFord(vector<vector<pair<int,int>>> &adj,int s,vector<bool> &reachable)
{
    int n=adj.size();
    vector<vector<int>> edges;
    for(int i=0;i<adj.size();i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            edges.push_back({i,adj[i][j].first,adj[i][j].second});
        }
    }
    vector<int> dist(n,-inf);
    dist[s]=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<edges.size();j++)
        {
            if(dist[edges[j][0]]!=-inf)
            {
                if(dist[edges[j][0]]+edges[j][2]>dist[edges[j][1]])
                {
                    dist[edges[j][1]]=dist[edges[j][0]]+edges[j][2];
                }
            }
        }
    }
    for(int j=0;j<edges.size();j++)
    {
        if((dist[edges[j][0]]!=-inf) && (dist[edges[j][0]]+edges[j][2]>dist[edges[j][1]]))
        {
            if(reachable[edges[j][0]]==true)
            {
                cout<<-1<<'\n';
                return;
            }
            dist[edges[j][1]]=dist[edges[j][0]]+edges[j][2];
        }
    }
    cout<<dist[n-1]<<'\n';
}

bool dfs(vector<vector<pair<int,int>>> &adj,int s,vector<bool> &vis,int target)
{
    vis[s]=true;
    if(s==target) return true;
    for(auto &x:adj[s])
    {
        if(!vis[x.first])
        {
            bool ans=dfs(adj,x.first,vis,target);
            if(ans==true) return true;
        }
    }
    return false;
}

void checkReachable(vector<vector<pair<int,int>>> &adj,vector<bool> &reachable)
{
    int n=adj.size();
    for(int i=0;i<n;i++)
    {
        vector<bool> vis(n);
        bool ans=dfs(adj,i,vis,n-1);
        reachable[i]=ans;
    }
}

int32_t main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        x--;y--;
        adj[x].push_back({y,w});
    }
    vector<bool> reachable(n);
    checkReachable(adj,reachable);
    bellmanFord(adj,0,reachable);
    return 0;
}