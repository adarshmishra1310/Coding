#include <bits/stdc++.h>
using namespace std;
#define int long long

const int inf = (int)1e18;
const int mod = 1e9 + 7;

void runCase(int &testcase)
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    if(is_sorted(v.begin(),v.end()))
    {
        cout<<"NO\n";
        return;
    }
    int a,b;
    for(int i=0;i<n-1;i++)
    {
        if(v[i]>v[i+1])
        {
            a=v[i];
            b=v[i+1];
            break;
        }
    }
    cout<<"YES\n";
    cout<<2<<'\n';
    cout<<a<<' '<<b<<'\n';
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