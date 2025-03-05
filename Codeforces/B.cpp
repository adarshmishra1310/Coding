#include <bits/stdc++.h>
using namespace std;
#define int long long

//const int inf = (int)1e18;
//const int mod = 1e9 + 7;

void runCase(int &testcase)
{
    int n,c;
    cin>>n>>c;
    string s;
    cin>>s;
    map<char,int> mpp;
    for(int i=0;i<n;i++) mpp[s[i]]++;
    vector<int> v;
    for(auto &x:mpp) v.push_back(x.second);
    sort(v.begin(),v.end());
    int sz=v.size(),cnt=0,temp=1;
    for(int i=0;i<sz;i++)
    {
        // cout<<v[i]<<' ';
        int t=0;
        if(temp<=c)
        {
            while(v[i]!=0 && temp<=c)
            {
                v[i]--;
                t+=temp;
                temp++;
            }
            if(v[i]!=0) cnt+=c;
            else cnt+=t;
            // cout<<temp<<'\n';
        }
        else if(v[i]!=0) cnt+=c;
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