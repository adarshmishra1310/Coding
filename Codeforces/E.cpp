#include <bits/stdc++.h>
using namespace std;
const int inf =(int)1e+18;
const int mod =(int)1e9+7;

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


void runcase(int &testcase){
    int n,m,k;
    cin >> n >> k;
    vector<int> a(n);
    _multiset<int> ms;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        ms.insert(a[i]);
    }
    int l=0,r=n-1;
    while(l<r) {
        if(a[l]==a[r]) {
            l++,r--;
        }
        else {
            if(ms.order_of_key(max(a[l],a[r])+1) >= k){
                ms.erase(ms.upper_bound(max(a[l],a[r])));
                if(a[l]>a[r]) l++;
                else r--;
            }
            else{
                cout<<"NO\n";
                return;
            }
        } 
    }
    cout<< "YES\n";
    
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tests=1;
    cin >> tests;
    for(int i=1;i<=tests;i++) runcase(i);
    return 0;
}