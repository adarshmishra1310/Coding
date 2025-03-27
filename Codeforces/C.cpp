#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int a, b; // For adjacency list: a = neighbor, b = weight.
    Node *next;
};

struct Heap
{
    Node *nodes; // For heap: a = distance, b = vertex.
    int size, capacity;
};

Heap *build_heap()
{
    Heap *hp = (Heap *)malloc(sizeof(Heap));
    hp->size = 0;
    hp->capacity = 1;
    hp->nodes = (Node *)malloc(hp->capacity * sizeof(Node));
    return hp;
}

void swap(Node *a, Node *b)
{
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(Heap *heap, int id)
{
    if (id && heap->nodes[id].a < heap->nodes[(id - 1) / 2].a)
    {
        swap(&heap->nodes[id], &heap->nodes[(id - 1) / 2]);
        heapifyUp(heap, (id - 1) / 2);
    }
}

void insert(Heap *heap, int a, int b)
{
    if (heap->size == heap->capacity)
    {
        heap->capacity++; // or multiply by 2
        heap->nodes = (Node *)realloc(heap->nodes, heap->capacity * sizeof(Node));
    }
    heap->nodes[heap->size].a = a;
    heap->nodes[heap->size].b = b;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
}

void heapifyDown(Heap *heap, int id)
{
    int sm = id;
    int left = 2 * id + 1;
    int right = 2 * id + 2;
    if (left < heap->size && heap->nodes[left].a < heap->nodes[sm].a)
        sm = left;
    if (right < heap->size && heap->nodes[right].a < heap->nodes[sm].a)
        sm = right;
    if (sm != id)
    {
        swap(&heap->nodes[id], &heap->nodes[sm]);
        heapifyDown(heap, sm);
    }
}

Node removeMin(Heap *heap)
{
    Node min = heap->nodes[0];
    heap->nodes[0] = heap->nodes[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return min;
}

// Here, 'adj' is an array of pointers to Node (the head of each vertex's linked list)
int *dijkstra(Node **adj, int n, int source)
{
    int *dist = (int *)malloc(n * sizeof(int));
    int *par = (int *)malloc(n * sizeof(int));
    int *vis = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        dist[i] = 1000000000; // large number
        vis[i] = 0;
        par[i] = -1;
    }

    Heap *hp = build_heap();
    dist[source] = 0;
    insert(hp, 0, source);

    while (hp->size > 0)
    {
        Node q = removeMin(hp);
        int v = q.b;
        if (vis[v] == 1)
            continue;
        vis[v] = 1;
        Node *temp = adj[v];
        while (temp != NULL)
        {
            int child_v = temp->a; // neighbor vertex
            int wt = temp->b;      // edge weight
            if (dist[v] + wt < dist[child_v])
            {
                dist[child_v] = dist[v] + wt;
                par[child_v] = v;
                insert(hp, dist[child_v], child_v);
            }
            temp = temp->next;
        }
    }

    return dist;
}

// Depth First Search (recursive)
void DFS(Node **adj, int u, int n, int *visited)
{
    visited[u] = 1;
    printf("Visited %d\n", u);
    Node *curr = adj[u];
    while (curr != NULL)
    {
        int v = curr->a;
        if (!visited[v])
            DFS(adj, v, n, visited);
        curr = curr->next;
    }
}

// Breadth First Search using a simple queue implementation
void BFS(Node **adj, int n, int start)
{
    // Allocate and initialize visited array and queue
    int *visited = (int *)calloc(n, sizeof(int));
    int *queue = (int *)malloc(n * sizeof(int));
    int front = 0, rear = 0;

    // Mark the start vertex as visited and enqueue it
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear)
    {
        int u = queue[front++];
        printf("Visited %d\n", u);

        Node *curr = adj[u];
        while (curr != NULL)
        {
            int v = curr->a;
            if (!visited[v])
            {
                visited[v] = 1;
                queue[rear++] = v;
            }
            curr = curr->next;
        }
    }
}

void addEdge(Node **adj, int u, int v, int w)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->a = v;
    newNode->b = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

int main()
{
    // Example: Create a graph with n vertices.
    int n = 5;
    Node **adj = (Node **)malloc(n * sizeof(Node *));
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    // To add an edge from u to v with weight w:
    // Example edges
    // addEdge(adj,0, 1, 10);
    // addEdge(adj,0, 2, 3);
    // addEdge(adj,1, 2, 1);
    // addEdge(adj,1, 3, 2);
    // addEdge(adj,2, 1, 4);
    // addEdge(adj,2, 3, 8);
    // addEdge(adj,2, 4, 2);
    // addEdge(adj,3, 4, 7);
    // addEdge(adj,4, 3, 9);

    int source = 0;
    int *dist = dijkstra(adj, n, source);

    printf("DFS traversal starting from vertex 0:\n");
    int *visited = (int *)calloc(n, sizeof(int));
    DFS(adj, 0, n, visited);

    printf("\nBFS traversal starting from vertex 0:\n");
    BFS(adj, n, 0);

    for (int i = 0; i < n; i++)
        printf("Distance from %d to %d: %d\n", source, i, dist[i]);
    return 0;
}
