#include <bits/stdc++.h>
using namespace std;
#define int long long

//const int inf = (int)1e18;
//const int mod = 1e9 + 7;

void runCase(int &testcase)
{
    int n;
    cin>>n;
    vector<int> v(n+1);
    for(int i=0;i<n+1;i++) cin>>v[i];
    vector<vector<int>> dp(n+1,vector<int>(n+1,1e9));
    vector<vector<int>> kk(n+1,vector<int>(n+1,0));
    for(int i=0;i<n+1;i++) dp[i][i]=0;
    for(int s=0;s<=n-1;s++)
    {
        for(int i=1;i<=n-s;i++)
        {
            int j=i+s;
            int mn=INT_MAX,mk=0;
            for(int k=i;k<j;k++)
            {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+v[i-1]*v[k]*v[j]);
                if(mn>=dp[i][j])
                {
                    mn=dp[i][j];
                    mk=k;
                } 
            }
            kk[i][j]=mk;
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(dp[i][j]==1e9) cout<<0<<' ';
            else cout<<dp[i][j]<<' ';
        }
        cout<<'\n';
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<kk[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<dp[1][n]<<'\n';
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for (int i = 1; i <= tests; i++)
    {
        // cout << "Case #" << i << ": \n";
        runCase(i);
    }
    return 0;
}