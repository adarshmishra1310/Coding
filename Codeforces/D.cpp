#include <bits/stdc++.h>
using namespace std;
// #define int long long

const int inf = (int)1e18;
const int mod = 1e9 + 7;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using _set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// X.find_by_order(k) return iterator of kth element. 0 indexed.
// X.order_of_key(k) returns count of elements strictly less than k.
template <typename T>
using _multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class key, class value, class cmp = std::less<key>>
using _map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

void runCase(int &testcase)
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(auto &x:v) cin>>x;
    _multiset<int> ms;
    for(int i=0;i<n;i++)
    {
        ms.insert(v[i]);
    }
    int l=0,r=n-1;
    while(l<r)
    {
        while(l<=r && v[l]==v[r]) 
        {
            l++,r--;
        }
        if(l>=r) break;
        int elem=max(v[l],v[r]);
        if(ms.order_of_key(elem+1)>=k)
        {
            if(v[l]==elem) l++;
            else r--;
            auto it=ms.upper_bound(elem);
            ms.erase(it);
        }
        else
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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