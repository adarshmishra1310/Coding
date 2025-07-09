#include <bits/stdc++.h>
using namespace std;

//Minimum cost path question(GFG)
// 3341. Find Minimum Time to Reach Last Room I -> Good question 

vector<vector<int>> moves = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};

bool isvalid(int i, int j, int n)
{
    return (i >= 0 && j >= 0 && i < n && j < n);
}

vector<vector<int>> dijkstra(vector<vector<int>> &grid, int N, vector<vector<bool>> &vis)
{
    vector<vector<int>> dist(N, vector<int>(N, INT_MAX));

    set<pair<int, pair<int, int>>> st; // {weight , node}

    st.insert({grid[0][0], {0, 0}});
    dist[0][0] = grid[0][0];

    while (st.size() > 0)
    {
        auto node = *st.begin();
        st.erase(st.begin());
        pair<int, int> v = node.second;
        int dis = node.first;
        if (vis[v.first][v.second] == true)
            continue;
        else
            vis[v.first][v.second] = true;
        for (auto &e : moves)
        {
            int i = v.first + e[0];
            int j = v.second + e[1];
            if (!isvalid(i, j, grid.size()))
                continue;
            int wt = grid[i][j];
            if (dist[v.first][v.second] + wt < dist[i][j]) // Relax
            {
                dist[i][j] = dist[v.first][v.second] + wt;
                // parent[child_v] = v; // Set the parent node
                st.insert({dist[i][j], {i, j}});
            }
        }
    }
    return dist;
}

int minimumCostPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<vector<bool>> vis(n, vector<bool>(n));
    vector<vector<int>> dist = dijkstra(grid, n, vis);
    return dist[n - 1][n - 1];
}

int main()
{

    return 0;
}