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
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int sz=n/k;
    int l=0,r=10,ans=0;
    _set<int> ss;
    set<int> st;
    while(l<=r)
    {
        int mid=(l+r)/2;
        cout<<mid<<' ';
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            ss.insert(v[i]);
            st.insert(v[i]);
            // if(mid==0)
            // {
            //     if(st.find(0)!=st.end())
            //     {
            //         ss.clear();
            //         st.clear();
            //         cnt++;
            //     }
            // }
            // else if(st.find(mid-1)!=st.end())
            // {
                int temp=ss.order_of_key(mid);
                if(temp==mid-1)
                {
                    ss.clear();
                    st.clear();
                    cnt++;
                }
            // }
        }
        cout<<cnt<<'\n';
        if(cnt<k)
        {
            r=mid-1;
        }
        else
        {
            ans=mid;
            l=mid+1;
        }
    }
    cout<<ans<<'\n';
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