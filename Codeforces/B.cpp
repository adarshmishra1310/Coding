
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
