#include <bits/stdc++.h>
using namespace std;

bool DFS(vector<int> adj[], vector<bool> &visited, int src, vector<bool> &recst)
{
    visited[src] = true;
    recst[src] = true;
    for (int x : adj[src])
    {
        if (visited[x] == false && DFS(adj, visited, x, recst))
        {
            return true;
        }
        else if (recst[x] == true)
            return true;
    }
    recst[src] = false;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> visited(V), recst(V);
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            bool ans = DFS(adj, visited, i, recst);
            if (ans == true)
                return true;
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        // adj[y].push_back(x);
    }

    vector<int> parent(n);
    vector<bool> vis(n);
    vector<bool> st(n);
    function<void(int64_t, int64_t, int64_t &)> dfs = [&](int64_t v, int64_t par, int64_t &val)
    {
        parent[v] = par;
        vis[v] = 1;
        st[v] = 1;
        for (auto &e : adj[v])
        {
            if (!vis[e])
            {
                dfs(e, v, val);
            }
            else if (st[e] == 1)
            {
                if (e != par)
                {
                    int64_t ll = 1, cc = v;
                    while (cc != e)
                    {
                        cc = parent[cc];//cycle reconstruction
                        ll++;
                    }
                    cout << ll << " ";
                    //   if(ll&1) val = 1;
                }
            }
        }
        st[v] = 0;
    };
    return 0;
}