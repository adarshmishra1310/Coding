#include <bits/stdc++.h>
using namespace std;
#define int long long

//const int inf = (int)1e18;
//const int mod = 1e9 + 7;

void runCase(int &testcase)
{
    int x,y,k;
    cin>>x>>y>>k;
    if(y>x) swap(x,y);
    int cnt=0;
    if(abs(x-y)==k)
    {
        cout<<cnt<<'\n';
        return;
    }
    while(abs(x-y)<k)
    {
        x++;
        y--;
        cnt++;
        if(abs(x-y)==k)
        {
            cout<<cnt<<'\n';
            return;
        }
        else if(abs(x-y)>k) 
        {
            cout<<-1<<'\n';
            return;
        }
    }
    while(abs(x-y)>k)
    {
        x--;
        y++;
        cnt++;
        if(abs(x-y)==k)
        {
            cout<<cnt<<'\n';
            return;
        }
        else if(abs(x-y)<k) 
        {
            cout<<-1<<'\n';
            return;
        }
    }
    cout<<-1<<'\n';
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