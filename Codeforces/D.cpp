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
    int c0=0,c1=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]=='0' && a[i]==b[i]) c0++;
        else if(a[i]=='1' && a[i]==b[i]) c1++;
    }
    if(n%2==0)
    {
        if(c0%2!=0 || c1%2!=0)
        {
            cout<<"NO\n";
            return;
        }
    }
    else
    {
        if((c0%2!=0 && c1%2!=0))
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