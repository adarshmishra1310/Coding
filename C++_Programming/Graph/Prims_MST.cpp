#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// Minimum spanning tree -> The Minimum Spanning Tree (MST) is the collection of edges required to connect all vertices in an undirected graph, with the minimum total edge weight.
//  A minimum spanning tree of a graph is unique, if the weight of all the edges are distinct. Otherwise, there may be multiple minimum spanning trees.

// Prims Algorithm
/*
    => Doesn't work for unconnected Graph
    => Working:-
        1. Choose a random vertex as the starting point, and include it as the first vertex in the MST.
        2. Compare the edges going out from the MST. Choose the edge with the lowest weight that connects a vertex among the MST vertices to a vertex outside the MST.
        3. Add that edge and vertex to the MST.
        4. Keep doing step 2 and 3 until all vertices belong to the MST.
    => Documentation:- https://cp-algorithms.com/graph/mst_prim.html
    => Visual Representation:- https://www.w3schools.com/dsa/dsa_algo_mst_prim.php
    => Time Complexity -> O(V^2) using array, O(E*logV) using priority queue(set)
    => For dense graph -> Array is better, For sparse graph -> priority queue(set) is better
*/
vector<int> primsMST(vector<vector<pair<int,int>>> &adj)
{
    // Array Implementation
    // Time Comlexity -> O(V^2)
    int n = adj.size(),total_weight = 0;
    vector<int> key(n, INF);        // Stores minimum weights to add a vertex
    vector<bool> inMST(n, false);   // Tracks whether a vertex is included in MST
    vector<int> parent(n, -1);      // Stores parent of each vertex in MST

    key[0] = 0; // Start from vertex 0

    for (int i = 0; i < n; ++i) {
        // Find the vertex u not in MST with the smallest key value
        int u = -1;
        for (int v = 0; v < n; ++v)
            if (!inMST[v] && (u == -1 || key[v] < key[u]))
                u = v;

        inMST[u] = true; // Include u in MST
        total_weight += key[u];
        // Update key and parent for all adjacent vertices of u(currently added vertex)
        for (auto [v, wt] : adj[u]) {
            if (!inMST[v] && wt < key[v]) {
                key[v] = wt;
                parent[v] = u;
            }
        }
    }

    cout<<"Total Weight of MST: "<<total_weight<<'\n';
    // Print the edges of the MST
    for (int v = 1; v < n; ++v)
        cout << parent[v] << " - " << v << endl;
    return parent;
}



void add_edge(vector<vector<pair<int,int>>> &adj,int u,int v,int w)
{
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
}

int main()
{
    vector<vector<pair<int,int>>> adj(8);
    add_edge(adj, 0, 1, 4);  // A - B
    add_edge(adj, 0, 3, 3);  // A - D
    add_edge(adj, 1, 2, 3);  // B - C
    add_edge(adj, 1, 3, 5);  // B - D
    add_edge(adj, 1, 4, 6);  // B - E
    add_edge(adj, 2, 4, 4);  // C - E
    add_edge(adj, 2, 7, 2);  // C - H
    add_edge(adj, 3, 4, 7);  // D - E
    add_edge(adj, 3, 5, 4);  // D - F
    add_edge(adj, 4, 5, 5);  // E - F
    add_edge(adj, 4, 6, 3);  // E - G
    add_edge(adj, 5, 6, 7);  // F - G
    add_edge(adj, 6, 7, 5);  // G - H
    primsMST(adj);
    return 0;
}