#include <bits/stdc++.h>
using namespace std;
#define int long long

//const int inf = (int)1e18;
//const int mod = 1e9 + 7;

void runCase(int &testcase)
{
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    vector<vector<int>> temp;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=b[i])
        {
            if((i<n-1) && (a[i]!=a[i+1]) && (a[i+1]!=b[i+1]))
            {
                // cout<<2<<' '<<i+1<<' '<<i+2<<'\n';
                temp.push_back({2,i+1,i+2});
                i++;
            }
            else if((i<n-1) && (a[i]==a[i+1]) && (a[i+1]!=b[i+1]))
            {
                // cout<<1<<' '<<i+1<<' '<<i+2<<'\n';
                temp.push_back({1,i+1,i+2});
                i++;
            }
            else
            {
                // cout<<1<<' '<<(i+1)<<' '<<(i+1)<<'\n';
                temp.push_back({1,i+1,i+1});
            }
        }
    }
    cout<<temp.size()<<'\n';
    for(auto &x:temp)
    {
        cout<<x[0]<<' '<<x[1]<<' '<<x[2]<<'\n';
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