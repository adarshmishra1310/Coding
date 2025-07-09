#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF = 1e9 + 10;

// Single source shortest path in directed/undirected graph
// TC -> O(V + E*log(V))
// Doesn't works in case of -ve edges

vector<long long> dijkstra(vector<vector<pair<int, int>>>& adj, int N, int source, vector<int> &parent)
{
    vector<long long> dist(N, INT64_MAX);

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq; // {weight , node}

    pq.push({0, source});
    dist[source] = 0;
    // parent.assign(N,-1);

    while (!pq.empty())
    {
        auto [dis, v] = pq.top();
        pq.pop();
        if (dis > dist[v])
            continue;
        for (auto [child_v,wt] : adj[v])
        {
            if (dist[v] + wt < dist[child_v]) // Relax
            {
                dist[child_v] = dist[v] + wt;
                // parent[child_v] = v; // Set the parent node
                pq.push({dist[child_v], child_v});
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