#include <bits/stdc++.h>
using namespace std;
#define int long long

//const int inf = (int)1e18;
//const int mod = 1e9 + 7;

void runCase(int &testcase)
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int ans=0;
    if(k==1)
    {
        int e2=0;
        for(int i=1;i<n-1;i++) e2=max(v[i],e2); 
        ans=max(ans,e2+max(v[0],v[n-1]));
        ans=max(ans,v[0]+v[n-1]);
        cout<<ans<<'\n';
        return;
    }
    sort(v.begin(),v.end());
    while((k+1)>0)
    {
        ans+=v.back();
        v.pop_back();
        k--;
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