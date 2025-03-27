#include <bits/stdc++.h>
using namespace std;
#define int long long

// const int inf = (int)1e18;
// const int mod = 1e9 + 7;

void runCase(int &testcase)
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> v[i][j];

    vector<vector<char>> c(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> c[i][j];
    
    int a=0,b=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(c[i][j]=='1') a+=v[i][j];
            else b+=v[i][j];
        }
    }
    if(abs(a-b)==0)
    {
        cout<<"YES\n";
        return;
    }
    else if(abs(a-b)%2!=0) 
    {
        cout<<"NO\n";
        return;
    }
    else if(k%2!=0)
    {
        cout<<"NO\n";
        return;
    }
    bool flag=0;
    vector<vector<int>> pfs(n,vector<int>(m));
    pfs[0][0]=(c[0][0]=='1');
    for(int i=1;i<m;i++)
    {
        pfs[0][i]=pfs[0][i-1]+(c[0][i]=='1');
    }
    for(int i=1;i<n;i++)
    {
        pfs[i][0]=pfs[i-1][0]+(c[i][0]=='1');
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            pfs[i][j]=pfs[i-1][j]+pfs[i][j-1]-pfs[i-1][j-1]+(c[i][j]=='1');
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<pfs[i][j]<<' ';
        }
        cout<<'\n';
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