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
    int ans=1;
    for(int i=0;i<n-1;i++)
    {
        int elem=lcm(v[i],v[i+1])/v[i+1];
        ans=lcm(ans,elem);
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