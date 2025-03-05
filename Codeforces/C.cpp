#include <bits/stdc++.h>
using namespace std;
#define int long long

//const int inf = (int)1e18;
//const int mod = 1e9 + 7;

void runCase(int &testcase)
{
    int n,m;
    cin>>n>>m;
    vector<int> ans;
    ans.push_back(n);
    int i=0;
    while((n|(1LL<<i))<=m)
    {
        if(((1LL<<i)&n)==0)
        {
            ans.push_back(n|(1LL<<i));
        }
        // cout<<(1<<i)<<' ';
        i++;
    }
    if(ans.size()<2)
    {
        cout<<-1<<'\n';
        return;
    }
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
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