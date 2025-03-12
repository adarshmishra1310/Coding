#include <bits/stdc++.h>
using namespace std;
#define int long long

//const int inf = (int)1e18;
//const int mod = 1e9 + 7;

void runCase(int &testcase)
{
    int n;
    cin>>n;
    vector<int> x(n),y(n);
    for(int i=0;i<n;i++) cin>>x[i];
    for(int i=0;i<n;i++) cin>>y[i];
    // map<int,int> mpp;
    int p=y[0];
    vector<pair<int,int>> temp;
    for(int i=0;i<n;i++)
    {
        temp.push_back({abs(x[i]-p),x[i]});
    }
    sort(temp.begin(),temp.end());
    for(int i=0;i<n;i++)
    {
        if(temp[i].second!=y[i])
        {
            cout<<-1<<'\n';
            return;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(x[i]==p){
            cout<<i+1<<'\n';
            return;
        }
    }
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