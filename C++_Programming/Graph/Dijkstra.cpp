#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF = 1e9 + 10;

// Single source shortest path in directed/undirected graph
// TC -> O(V + E*log(V))
// Doesn't works in case of -ve edges

vector<int> dijkstra(vector<pair<int, int>> adj[], int N, int source, vector<bool> &vis, vector<int> &parent)
{
    vector<int> dist(N, INT_MAX);

    set<pair<int, int>> st; // {weight , node}

    st.insert({0, source});
    dist[source] = 0;

    while (st.size() > 0)
    {
        auto node = *st.begin();
        st.erase(st.begin());
        int v = node.second;
        int dis = node.first;
        if (vis[v] == true)
            continue;
        else
            vis[v] = true;
        for (auto child : adj[v])
        {
            int child_v = child.first;
            int wt = child.second;
            if (dist[v] + wt < dist[child_v]) // Relax
            {
                dist[child_v] = dist[v] + wt;
                parent[child_v] = v; // Set the parent node
                st.insert({dist[child_v], child_v});
            }
        }
    }
    return dist;
}

vector<int> getPath(int source, int destination, vector<int> &parent)
{
    vector<int> path;
    int currentNode = destination;

    while (currentNode != -1)
    {
        path.push_back(currentNode);
        currentNode = parent[currentNode];
    }

    reverse(path.begin(), path.end());

    if (path[0] == source)
        return path; // Path from source to destination
    else
        return {}; // If no valid path exists
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n]; //{node,weight}
    for (int i = 0; i < n; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        adj[x].push_back({y, wt});
        // adj[y].push_back({x,wt});//for undirected graph
    }
    vector<int> parent(N, -1); // To store the parent of each node
    return 0;
}