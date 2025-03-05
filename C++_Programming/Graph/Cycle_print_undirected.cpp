#include <bits/stdc++.h>
using namespace std;
#define int long long

//const int inf = (int)1e18;
//const int mod = 1e9 + 7;

bool dfs(vector<vector<int>> &adj,int s,vector<bool> &vis,vector<int> &par)
{
    vis[s]=true;
    for(auto &x:adj[s])
    {
        if(!vis[x])
        {
            par[x]=s;
            int flag=dfs(adj,x,vis,par);
            if(flag==1) return true;
        }
        else if(x!=par[s])
        {
            int temp=s,cnt=0,l=2;
            vector<int> ans;
            ans.push_back(x);
            while(temp!=x)
            {
                ans.push_back(temp);
                temp=par[temp];
                cnt++;
            }
            if(cnt>=2)
            {
                cout<<ans.size()+1<<'\n';
                for(auto &x:ans)
                {
                    cout<<x+1<<' ';
                }
                cout<<ans[0]+1<<' ';
                cout<<'\n';
                return true;
            }
        }
    }
    return false;
}

void runCase(int &testcase)
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        --x,--y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool> vis(n);
    vector<int> par(n,-1);
    bool flag=0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i]) 
        {
            bool flag=dfs(adj,i,vis,par);
            if(flag) return;
        }
    }
    cout<<"IMPOSSIBLE\n";
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