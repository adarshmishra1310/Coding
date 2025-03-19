
#include <bits/stdc++.h>
using namespace std;
int64_t inf = (int64_t)1e+18;
int64_t mod = 1000000007;

struct heap {
    int n = 0, mx = 0;
    int *arr = (int *)malloc(n * sizeof(int));
    int cmp = 0;

    heap(int x) : cmp(x) {}

    bool compare(int a, int b) {
        if (cmp == 1) {
            // max - heap
            return a > b;
        } else {
            // min-heap
            return a < b;
        }
    }

    void sift_up(int i) {
        while (i > 0 && compare(arr[i], arr[(i - 1) / 2])) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void sift_down(int i, int *B, int sz) {
        while (2 * i + 1 < sz) {
            int j = 2 * i + 1;
            if (2 * i + 2 < sz && compare(B[2 * i + 2], B[j])) j = 2 * i + 2;
            if (compare(B[i], B[j])) break;
            swap(B[i], B[j]);
            i = j;
        }
    }

    void push(int x) {
        n++, mx++;
        arr = (int *)realloc(arr, n * sizeof(int));
        arr[n - 1] = x;
        sift_up(n - 1);
    }

    int pop() {
        int res = arr[0];
        swap(arr[0], arr[n - 1]);
        n--;
        sift_down(0, arr, n);
        return res;
    }

    void heapify(int *A, int n) {
        for (int i = n - 1; i >= 0; i--) sift_down(i, A, n);
    }
};

void runCase(int64_t &testCase) {
    // cout << "#Case " << testCase << ": \n";

    heap Hp(1);
    int n;
    cin >> n;
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[i] = x;
        Hp.push(x);
    }
    for (int i = 0; i < Hp.mx; i++) {
        cout << Hp.arr[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        Hp.pop();
    }
    for (int i = 0; i < Hp.mx; i++) {
        cout << Hp.arr[i] << " ";
    }
    cout << "\n";

    Hp.heapify(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t tests = 1;
    // cin >> tests;
    for (int64_t i = 1; i <= tests; i++) runCase(i);

    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>

// void swap(int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// void heapify(int arr[], int size, int i, int isMaxHeap) {
//     int extreme = i;
//     int left = 2 * i + 1;
//     int right = 2 * i + 2;

//     if (left < size && ((isMaxHeap && arr[left] > arr[extreme]) || (!isMaxHeap && arr[left] < arr[extreme])))
//         extreme = left;
//     if (right < size && ((isMaxHeap && arr[right] > arr[extreme]) || (!isMaxHeap && arr[right] < arr[extreme])))
//         extreme = right;

//     if (extreme != i) {
//         swap(&arr[i], &arr[extreme]);
//         heapify(arr, size, extreme, isMaxHeap);
//     }
// }

// void push(int **arr, int *size, int value, int isMaxHeap) {
//     *size += 1;
//     *arr = realloc(*arr, (*size) * sizeof(int));
//     (*arr)[*size - 1] = value;

//     int i = *size - 1;
//     while (i > 0 && ((isMaxHeap && (*arr)[(i - 1) / 2] < (*arr)[i]) || (!isMaxHeap && (*arr)[(i - 1) / 2] > (*arr)[i]))) {
//         swap(&(*arr)[i], &(*arr)[(i - 1) / 2]);
//         i = (i - 1) / 2;
//     }
// }

// int pop(int **arr, int *size, int isMaxHeap) {
//     if (*size == 0) return -1;

//     int root = (*arr)[0];
//     (*arr)[0] = (*arr)[--(*size)];
//     *arr = realloc(*arr, (*size) * sizeof(int));
//     heapify(*arr, *size, 0, isMaxHeap);

//     return root;
// }

// void heapSort(int arr[], int n) {
//     for (int i = n / 2 - 1; i >= 0; i--)
//         heapify(arr, n, i, 1);

//     for (int i = n - 1; i > 0; i--) {
//         swap(&arr[0], &arr[i]);
//         heapify(arr, i, 0, 1);
//     }
// }

// void printHeap(int arr[], int size) {
//     for (int i = 0; i < size; i++)
//         printf("%d ", arr[i]);
//     printf("\n");
// }

// int main() {
//     int *heap = NULL, size = 0;

//     push(&heap, &size, 10, 1);
//     push(&heap, &size, 20, 1);
//     push(&heap, &size, 15, 1);
//     push(&heap, &size, 30, 1);

//     printf("Max Heap: ");
//     printHeap(heap, size);

//     printf("Popped: %d\n", pop(&heap, &size, 1));
//     printHeap(heap, size);

//     int arr[] = {4, 10, 3, 5, 1};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     heapSort(arr, n);
//     printf("Heap Sorted Array: ");
//     for (int i = 0; i < n; i++)
//         printf("%d ", arr[i]);
//     printf("\n");

//     free(heap);
//     return 0;
// }
