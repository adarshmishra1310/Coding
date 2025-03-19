#include <bits/stdc++.h>
using namespace std;
#define int long long

//const int inf = (int)1e18;
//const int mod = 1e9 + 7;

void runCase(int &testcase)
{
    // logic
    // make a pair of multiset or vector where elements are {v[i]%k,i}. 
    // run a loop
    // find {k-(v[i]%k),-1} ka lower bound in multiset. check if element is present or not
    // if it present then map that element with v[i] and erase these from multiset
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for (int i = 1; i <= tests; i++)
    {
        // cout << "Case #" << i << ": \n";
        runCase(i);
    }
    return 0;
}