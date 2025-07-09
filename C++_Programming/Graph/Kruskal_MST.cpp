#include <bits/stdc++.h>
using namespace std;

// Minimum spanning tree -> The Minimum Spanning Tree (MST) is the collection of edges required to connect all vertices in an undirected graph, with the minimum total edge weight.
//  A minimum spanning tree of a graph is unique, if the weight of all the edges are distinct. Otherwise, there may be multiple minimum spanning trees.

// Possible MSTs -> mC(n-1) - no. of cycles

// Kruskal Algorithm:-
/*
    1. Always select the minimum edge weight from the graph and connect them
    2. If connecting them will make a cycle then don't connect them
    3. Repeat this process until all vetices are connected to single id

    DSU logic:-
    1. intialize dsu with n connected components
    2. store edges and then sort them by weight
    3. iterate in edge from smallest weight to largest
    4. if in edge two nodes u and v has edge between them and they belong from different components then connect them, else if they belong from same component then don't connect otherwise it will make a cycle
*/

bool mycmp(vector<int> &x,vector<int> &y)
{
    return x[2]<y[2];
}

struct DSU {
    vector<int> par, rnk, sz;
    int c;
    DSU(int n) : par(n + 1), rnk(n + 1, 0), sz(n + 1, 1), c(n) {
        for (int i = 1; i <= n; ++i) par[i] = i;
    }
    int find(int i) {
        return (par[i] == i ? i : (par[i] = find(par[i])));
    }
    bool same(int i, int j) {
        return find(i) == find(j);
    }
    int get_size(int i) {
        return sz[find(i)];
    }
    int count() {
        return c; // connected components
    }
    int join(int i, int j) {
        if ((i = find(i)) == (j = find(j)))
            return -1;
        else
            --c;
        if (rnk[i] > rnk[j]) swap(i, j);
        par[i] = j;
        sz[j] += sz[i];
        if (rnk[i] == rnk[j]) rnk[j]++;
        return j;
    }
};

vector<vector<pair<int,int>>> kruskalMST(vector<vector<pair<int,int>>> &adj)
{
    int n=adj.size();
    vector<vector<pair<int,int>>> adj2(n);
    vector<vector<int>> edge,result;
    for(int i=0;i<n;i++)
    {
        for(auto &x:adj[i])
        {
            edge.push_back({i,x.first,x.second});
        }
    }
    sort(edge.begin(),edge.end());
    DSU dsu(n);
    int cost=0;
    for(int i=0;i<edge.size();i++)
    {
        int u=edge[i][0],v=edge[i][1],w=edge[i][2];
        if(!dsu.same(u,v))
        {
            cost+=w;
            adj2[u].push_back({v,w});
            dsu.join(u,v);
        }
    }
    cout<<cost<<'\n';
    return adj2;
}

int main()
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
        adj[y].push_back({x,w});
    }
    vector<vector<pair<int,int>>> adj2 = kruskalMST(adj);
    return 0;
}