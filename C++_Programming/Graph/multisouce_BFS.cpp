#include <bits/stdc++.h>
using namespace std;

//const int inf = (int)1e18;
//const int mod = 1e9 + 7;

// CSES Problem -> Monsters

vector<vector<int>> dirc = {{-1,0},{1,0},{0,1},{0,-1}};

bool valid(vector<vector<char>> &v,int i,int j,int n,int m)
{
    return (i>=0) && (i<n) && (j>=0) && (j<m) && (v[i][j]!='#') && (v[i][j]!='M');
}

string dfs(vector<vector<char>> &v,int n,int m,int l,int r,vector<vector<bool>>& vis,vector<vector<int>> &distM,int t)
{
    // Got TLE on DFS
    vis[l][r]=true;
    if(l==n-1 || r==m-1 || l==0 || r==0) return "";
    string temp;
    for(auto &e:dirc)
    {
        int i=l+e[0],j=r+e[1];
        if(valid(v,i,j,n,m) && !vis[i][j] && ((t+1)<distM[i][j])) 
        {
            temp=dfs(v,n,m,i,j,vis,distM,t+1);
            if(temp!="NO") 
            {
                if(e[0]==0 && e[1]==1) temp='R'+temp;
                else if(e[0]==1 && e[1]==0) temp='D'+temp;
                else if(e[0]==-1 && e[1]==0) temp='U'+temp;
                else temp='L'+temp;
                return temp;
            }
        }
    }
    // cout<<l<<' '<<r<<'\n';
    vis[l][r]=false;
    return "NO";
}

string bfs(vector<vector<char>> &v,int n,int m,int l,int r,vector<vector<bool>>& vis,vector<vector<int>>& distM,int t)
{
    queue<pair<int,int>> q;
    q.push({l,r});
    vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
    vector<vector<pair<int,int>>> par(n,vector<pair<int,int>>(m));
    dist[l][r]=0;
    vis[l][r]=true;
    par[l][r]={-1,-1};
    while(!q.empty())
    {
        int cnt=q.size();
        while(cnt--)
        {
            pair<int,int> c=q.front();
            if(c.first==0 || c.second==0 || c.first==n-1 || c.second==m-1)
            {
                string temp;
                int i=c.first,j=c.second;
                while(1)
                {
                    pair<int,int> p=par[i][j];
                    if(p.first==-1 && p.second==-1) break;
                    if((p.first==i) && (p.second+1)==j) temp.push_back('R');
                    else if((p.first==i) && (p.second-1)==j) temp.push_back('L');
                    else if((p.first+1==i) && (p.second)==j) temp.push_back('D');
                    else if((p.first-1==i) && (p.second)==j) temp.push_back('U');
                    i=p.first,j=p.second;
                }
                reverse(temp.begin(),temp.end());
                return temp;
            }
            q.pop();
            for(auto &e:dirc)
            {
                int i=c.first+e[0],j=c.second+e[1];
                if(valid(v,i,j,n,m) && !vis[i][j] && ((dist[c.first][c.second]+1)<distM[i][j]))
                {
                    q.push({i,j});
                    vis[i][j]=true;
                    par[i][j]={c.first,c.second};
                    dist[i][j]=dist[c.first][c.second]+1;
                }
            }
        }
    }
    return "NO";
}

void multisourceBFS(vector<vector<char>> &v,vector<vector<int>> &distM)
{
    int n=v.size(),m=v[0].size();
    queue<pair<int,int>> q;
    vector<vector<bool>> vis(n,vector<bool>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(v[i][j]=='M')
            {
                distM[i][j]=0;
                q.push({i,j});
                vis[i][j]=true;
            }
        }
    }
    while(!q.empty())
    {
        int cnt=q.size();
        while(cnt--)
        {
            pair<int,int> c=q.front();
            q.pop();
            for(auto &e:dirc)
            {
                int i=c.first+e[0],j=c.second+e[1];
                if(valid(v,i,j,n,m) && !vis[i][j]) 
                {
                    q.push({i,j});
                    vis[i][j]=true;
                    distM[i][j]=min(distM[i][j],distM[c.first][c.second]+1);
                }
            }
        }
    }
}

void runCase(int &testcase)
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>> v(n,vector<char>(m));
    int l,r;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>v[i][j];
            if(v[i][j]=='A')
            {
                l=i;
                r=j;
            }
        }
    }

    vector<vector<int>> distM(n,vector<int>(m,INT_MAX));
    multisourceBFS(v,distM);

    vector<vector<bool>> vis(n,vector<bool>(m));
    string ans="";
    // ans=dfs(v,n,m,l,r,vis,distM,0);
    ans=bfs(v,n,m,l,r,vis,distM,0);
    if(ans!="NO")
    {
        cout<<"YES\n";
        cout<<ans.size()<<'\n';
    }
    cout<<ans<<'\n';

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