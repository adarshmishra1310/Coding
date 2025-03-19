#include <bits/stdc++.h>
using namespace std;

int sz = 0;
int *hp = (int *)malloc(sz * sizeof(int));

bool op(int a, int b)
{
    return (a >= b);
}

void insert(int x)
{
    sz++;
    hp = (int *)realloc(hp, sz * sizeof(int));
    hp[sz - 1] = x;
    int i = sz - 1;
    while (i > 0 && op(hp[i], hp[(i - 1) / 2]))
    {
        swap(hp[i], hp[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int del()
{
    int ans = hp[0];
    swap(hp[0], hp[sz - 1]);
    sz--;
    int i = 0;
    while (2 * i + 1 < sz)
    {
        int j = 2 * i + 1;
        if (2 * i + 2 < sz && op(hp[2 * i + 2], hp[j])) j = 2 * i + 2;
        if (op(hp[i], hp[j])) break;
        swap(hp[i], hp[j]);
        i = j;
    }
    return ans;
}

int main()
{
    insert(5);
    insert(10);
    insert(7);
    insert(2);
    for(int i=0;i<sz;i++) cout<<hp[i]<<' ';
    cout<<'\n';
    return 0;
}