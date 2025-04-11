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
    int l=0,r=n,ans=0;
    while(l<=r)
    {
        set<int> ss;
        int mid=(l+r)/2;
        int cnt=0;
        // make mid as mex means all elements less than mid should be there
        for(int i=0;i<n;i++)
        {
            if(v[i]<mid)
            {
                ss.insert(v[i]);
            }
            if(ss.size()==mid)
            {
                cnt++;
                ss.clear();
            }
        }
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