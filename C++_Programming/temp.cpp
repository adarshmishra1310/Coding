#include <bits/stdc++.h>
using namespace std;
#define int long long

//const int inf = (int)1e18;
const int mod = 1e9 + 7;

int binExp(int x,int n)
{
    int ans=1;
    while(n>0)
    {
        if(n&1) ans=(ans*x) % mod;
        x=(x*x) % mod; 
        n=n>>1;
    }
    return ans;
}

int binMultiply(int a,int b)
{
    int ans=0;
    while(b>0)
    {
        if(b&1) ans=(ans+a) % mod;
        a=(a+a) % mod;
        b=b>>1;
    }
    return ans;
}

void runCase()
{
    cout<<binMultiply(100,100)<<'\n';
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for (int i = 1; i <= tests; i++)
        runCase();
    return 0;
}