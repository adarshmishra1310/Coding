#include <bits/stdc++.h>
using namespace std;

int sz = 0, maxsz = 1;
int *hp = (int *)malloc(maxsz * sizeof(int));

bool op(int a, int b)
{
    if (a >= b)
        return true;
    else
        return false;
}

void insert(int x)
{
    hp = (int *)realloc(hp, (sz + 1) * sizeof(int));
    int idx = sz;
    hp[idx] = x;
    while (idx > 0)
    {
        int parent = (idx - 1) / 2;
        if (op(hp[idx], hp[parent]))
            swap(hp[idx], hp[parent]);
        else
            break;
        idx = parent;
    }
    sz++;
    maxsz++;
}

void del()
{
    sz--;
    hp[0] = hp[sz];
    int temp = 0;
    while (temp < sz)
    {
        int id = temp;
        if (op(hp[2 * temp], hp[0]) && op(hp[2 * temp + 1], hp[0]))
            if (op(hp[2 * temp], hp[2 * temp + 1]))
                temp = 2 * temp;
            else
                temp = 2 * temp + 1;
        else if (op(hp[2 * temp], hp[0]))
            temp = 2 * temp;
        else if (op(hp[2 * temp + 1], hp[0]))
            temp = 2 * temp + 1;
        else
            break;
    }
    swap(hp[temp], hp[0]);
}

int main()
{
    int n;
    cin >> n;
    int v[n];
    for (int i = 0; i < n; i++)
        cin >> v[i];
    insert(5);
    // for (int i = 0; i < sz; i++)
    // {
    //     cout << hp[i] << ' ';
    // }
    insert(10);
    insert(7);
    insert(2);
    del();
    del();
    for (int i = 0; i < sz; i++)
    {
        cout << hp[i] << ' ';
    }
    cout << '\n';
    return 0;
}