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
    int ans=INT_MAX;
    int a=INT_MAX,b=INT_MAX;
    ans=min(ans,v[0]+min(v[0],v[1]));
    a=v[0];
    b=max(v[0],v[1]);
    int sum=v[0]+min(v[0],v[1]),mn=min(v[0],v[1]);
    for(int i=2;i<n;i++)
    {
        ans=min(ans,sum);
        mn=min(mn,v[i]);
        sum+=v[i];
    }
    ans=min(ans,sum);
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