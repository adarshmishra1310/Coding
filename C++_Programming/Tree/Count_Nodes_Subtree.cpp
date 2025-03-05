#include <bits/stdc++.h>
using namespace std;
#define int long long

//const int inf = (int)1e18;
//const int mod = 1e9 + 7;

int dfs(vector<vector<int>> &adj,int s,vector<int> &res)
{
    int ans=0;
    for(auto &u:adj[s])
    {
        ans+=dfs(adj,u,res);
    }
    res[s]=ans;
    return 1+ans;
}

void runCase(int &testcase)
{
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i=2;i<=n;i++)
    {
        int x;
        cin>>x;
        adj[x].push_back(i);
    }
    vector<int> res(n+1);
    dfs(adj,1,res);
    for(int i=1;i<=n;i++)
    {
        cout<<res[i]<<' ';
    }
    cout<<'\n';

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