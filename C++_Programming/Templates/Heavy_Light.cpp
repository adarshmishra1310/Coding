#include <bits/stdc++.h>
using namespace std;

struct tree {
    int n;
    vector<vector<int>> adj;
    vector<int> size, depth, head, parent;
    tree(int n) : n(n), adj(n) {}

    void add_edge(int s, int t) {
        adj[s].push_back(t);
        adj[t].push_back(s);
    }

    void rootify(int r) {
        size = depth = parent = head = vector<int>(n, -1);

        function<int(int, int)> dfs = [&](int u, int p) {
            parent[u] = p;
            depth[u] = depth[p] + 1;
            for (int v : adj[u])
                if (v != p) size[u] += dfs(v, u);
            return ++size[u];
        };

        dfs(r, r);

        function<void(int, int)> dec = [&](int u, int s) {
            head[u] = s;
            int z = -1;
            for (int v : adj[u])
                if (head[v] < 0 && (z < 0 || size[z] < size[v])) z = v;
            for (int v : adj[u])
                if (head[v] < 0) dec(v, v == z ? s : v);
        };

        dec(r, r);
    }

    int lca(int u, int v) {
        while (head[u] != head[v])
            if (depth[head[u]] < depth[head[v]])
                v = parent[head[v]];
            else
                u = parent[head[u]];
        return depth[u] < depth[v] ? u : v;
    }

    int dist(int u, int v) {
        int l = lca(u, v);
        return depth[u] + depth[v] - (depth[l] << 1);
    }
};

int main()
{
    
    return 0;
}