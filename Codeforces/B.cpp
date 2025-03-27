// Adarsh Mishra
// 23CH10003
// Assignment no. - 7

#include <bits/stdc++.h>
using namespace std;

// Structure for a node in the heap
typedef struct Node
{
    long long a;
    long long b;
    long long key;
} Node;

// Structure of Heap of Nodes
typedef struct Heap
{
    Node *nodes;
    long long size;
    long long capacity;
} Heap;

// Function to build a new empty heap
Heap *buildHeap()
{
    Heap *heap = (Heap *)malloc(1 * sizeof(Heap));
    heap->size = 0;
    heap->capacity = 1;
    heap->nodes = (Node *)malloc(1 * sizeof(Node));
    return heap;
}

// Function to swap two nodes in the heap
void swap(Node *a, Node *b)
{
    Node temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify up
void heapifyUp(Heap *heap, long long id)
{
    if (id && heap->nodes[id].key < heap->nodes[(id - 1) / 2].key)
    {
        swap(&heap->nodes[id], &heap->nodes[(id - 1) / 2]);
        heapifyUp(heap, (id - 1) / 2);
    }
}

// Function to insert a new triple long longo the heap
void insert(Heap *heap, long long a, long long b, long long n)
{
    // Increasing capacity if heap becomes full
    if (heap->size == heap->capacity)
    {
        heap->capacity++;                                                          // increasing capacity by 1 (we can also increase by 2*capacity)
        heap->nodes = (Node *)realloc(heap->nodes, heap->capacity * sizeof(Node)); // Reallocating memory
    }
    if (a * a * a + b * b * b > n * n * n)
        return;
    // Assinging values
    heap->nodes[heap->size].a = a;
    heap->nodes[heap->size].b = b;
    heap->nodes[heap->size].key = a * a * a + b * b * b;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
}

// Function to heapify down
void heapifyDown(Heap *heap, long long id)
{
    long long sm = id;
    long long left = 2 * id + 1;
    long long right = 2 * id + 2;
    if (left < heap->size && heap->nodes[left].key < heap->nodes[sm].key)
    {
        sm = left;
    }
    if (right < heap->size && heap->nodes[right].key < heap->nodes[sm].key)
    {
        sm = right;
    }
    if (sm != id)
    {
        swap(&heap->nodes[id], &heap->nodes[sm]);
        heapifyDown(heap, sm);
    }
}

// Function to remove the item with sm key and restore the heap property
Node removeMin(Heap *heap)
{
    Node min = heap->nodes[0];
    // Assign last value as root of heap
    heap->nodes[0] = heap->nodes[heap->size - 1];
    // Decreasing the size of Heap
    heap->size--;
    heapifyDown(heap, 0);
    return min;
}

// Function to find all possible sum of cubes of [a,b] where a,b=0,1,2,...n in O(n) space complexity
void allPossibleSum(Heap *heap, long long n)
{
    // inserting all pairs (i,0,i^3) where i=0,1,....,n
    for (long long i = 0; i <= n; i++)
    {
        insert(heap, i, 0, n);
    }
    // Removing minimum node till heap becomes empty
    while (heap->size >= 1)
    {
        // Removing minimum element
        Node temp = removeMin(heap);
        bool flag = 1;
        // if temp.b+1 is less than n then check whether same key value exist or not
        if (temp.b + 1 < n)
        {
            long long aa = temp.a, bb = (temp.b + 1);
            // Check if pair with that key value exist
            for (long long i = 0; i < heap->size; i++)
            {
                if (heap->nodes[i].key == (aa * aa * aa + bb * bb * bb))
                {
                    // Excluding same pairs
                    if (min(heap->nodes[i].a, heap->nodes[i].b) == min(aa, bb) && max(heap->nodes[i].a, heap->nodes[i].b) == max(aa, bb))
                    {
                        flag = 0;
                        continue;
                    }
                    // Print the answer if found
                    cout << aa * aa * aa + bb * bb * bb << ' ';
                    cout << '(' << heap->nodes[i].a << ", " << heap->nodes[i].b << ") ";
                    cout << '(' << aa << ", " << bb << ")\n";
                }
            }
            // If pair doesn't found then insert
            if (flag)
                insert(heap, max(temp.a, temp.b + 1), min(temp.a, temp.b + 1), n);
        }
    }
}

// Function to compute cuberoot
long long cubeRoot(long long m)
{
    long long l = 0, r = 1;
    // taking upper range as 2^20 as maximum m can be 2^60
    for (long long i = 0; i < 20; i++)
        r *= 2;
    // Using binary search
    while (l <= r)
    {
        long long mid = l + (r - l) / 2;
        if (mid * mid * mid == m)
            return mid;
        else if (mid * mid * mid < m)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}

int32_t main()
{
    long long m;
    cout << "Enter M: ";
    cin >> m;
    long long n = (long long)cubeRoot(m);
    Heap *heap = buildHeap();
    allPossibleSum(heap, n);
    return 0;
}