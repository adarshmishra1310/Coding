#include <bits/stdc++.h>
using namespace std;
#define int long long

//const int inf = (int)1e18;
//const int mod = 1e9 + 7;

void runCase(int &testcase)
{
    int n,k;
    cin>>n>>k;
    if(n==1 && k==2)
    {
        cout<<"YES\n";
        return;
    }
    if(k>1)
    {
        cout<<"NO\n";
        return;
    }
    if(n==1)
    {
        cout<<"NO\n";
        return;
    }
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            cout<<"NO\n";
            return;
        }
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