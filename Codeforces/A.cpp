#include <bits/stdc++.h>
using namespace std;
#define int long long

//const int inf = (int)1e18;
//const int mod = 1e9 + 7;

void runCase(int &testcase)
{
    int x,y,z,a,b,c;
    cin>>x>>y>>z>>a>>b>>c;
    int cnt=0;
    if(z>=c)
    {
        cnt+=c;
        z-=c;
    }
    else
    {
        cnt+=z;
        z=0;
    }
    if(z>0) y+=z;
    if(y>=b)
    {
        cnt+=b;
        y-=b;
    }
    else
    {
        cnt+=y;
        y=0;
    }
    if(y>0) x+=y;
    if(x>=a)
    {
        cnt+=a;
        x-=a;
    }
    else
    {
        cnt+=x;
        x=0;
    }
    cout<<cnt<<'\n';

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