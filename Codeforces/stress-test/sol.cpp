#include <bits/stdc++.h>
using namespace std;
// #define int long long

//const int inf = (int)1e18;
//const int mod = 1e9 + 7;

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
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    _multiset<int> a,b;
    int id=-1;
    map<int,int> mpp;
    // for(int i=0;i<n;i++) 
    // {
    //     if(mpp.find(v[i])!=mpp.end()) break;
    //     mpp[v[i]]++;
    //     id++;
    // }
    for(int i=0;i<n;i++)
    {
        while((id+1<n) && mpp.find(v[id+1])==mpp.end())
        {
            mpp[v[id+1]]++;
            id++;
        }
        a.insert(id);
        mpp[v[i]]--;
        if(mpp[v[i]]==0) mpp.erase(v[i]);
    }
    mpp.clear();
    // cout<<'\n';
    id=n;
    for(int i=n-1;i>=0;i--)
    {
        while((id-1>=0) && mpp.find(v[id-1])==mpp.end())
        {
            mpp[v[id-1]]++;
            id--;
        }
        b.insert(id);
        mpp[v[i]]--;
        if(mpp[v[i]]==0) mpp.erase(v[i]);
    }
    vector<int> bb;
    for(auto &x:b)
    {
        bb.push_back(x);
    }
    long long cnt=0,i=0;
    for(auto &x:a)
    {
        cnt+=max(0LL,(long long)b.order_of_key(x+1)-i-1);
        i++;
        // cout<<cnt<<' ';
    }
    cout<<cnt<<'\n';

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