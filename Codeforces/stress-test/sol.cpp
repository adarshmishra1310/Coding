#include <bits/stdc++.h>
using namespace std;
#define int long long

//const int inf = (int)1e18;
//const int mod = 1e9 + 7;

void runCase(int &testcase)
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    string a,b;
    a=b="1";  
    int pd=INT_MIN;  
    for(int i=1;i<n;i++)
    {
        if(a.back()=='0') 
        {
            a+='0';
            continue;
        }
        if(v[i]>v[i-1] && (v[i]-v[i-1])>=pd+(n-3))
        {
            a+='1';
        }
        else a+='0';
        pd=v[i]-v[i-1];
    }
    pd=INT_MAX;
    for(int i=n-2;i>=0;i--)
    {
        if(*b.begin()=='0') 
        {
            b='0'+b;
            continue;
        }
        if(v[i]<v[i+1] && ((v[i+1]-v[i])<=pd-(n-3)))
        {
            b='1'+b;
        }
        else b='0'+b;
        pd=v[i+1]-v[i];
    }
    // cout<<a<<' '<<b<<'\n';
    string temp="";
    if(b[1]=='1') temp+='1';
    else temp+='0';
    for(int i=1;i<n-1;i++)
    {
        if(i>=2) pd=v[i-1]-v[i-2];
        else pd=INT_MIN;
        if(a[i-1]=='1' && b[i+1]=='1' && (v[i-1]<v[i+1] && (v[i+1]-v[i-1])>=pd+(n-3)))
        {
            if(i<n-2 && (v[i+2]-v[i+1])<(v[i+1]-v[i-1]+(n-3))) temp+='0';
            else temp+='1';
        }
        else temp+='0';
    }
    if(a[n-2]=='1') temp+='1';
    else temp+='0';
    cout<<temp<<'\n';
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