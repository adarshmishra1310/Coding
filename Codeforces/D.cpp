#include <bits/stdc++.h>
using namespace std;
#define int long long

//const int inf = (int)1e18;
//const int mod = 1e9 + 7;

// bool check(int mid,int x,int y,vector<int> &v)
// {

// }

void runCase(int &testcase)
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    int sum=accumulate(v.begin(),v.end(),0LL);
    int q;
    cin>>q;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        auto it=lower_bound(v.begin(),v.end(),x);
        if(it==v.end())
        {
            cout<<min(max(0ll,x-v[n-1])+max(0ll,y-sum+v[n-1]),max(0ll,x-v[0])+max(0ll,y-sum+v[0]))<<'\n';
            // int ans=INT_MAX;
            // for(int i=0;i<n;i++)
            // {
            //     ans=min(ans,max(0ll,x-v[i])+max(0ll,y-sum+v[i]));
            // }
            // cout<<ans<<'\n';
        }
        else
        {
            // int ans=INT_MAX,ind=0;
            // for(int i=0;i<n;i++)
            // {
            //     if(ans>max(0ll,x-v[i])+max(0ll,y-sum+v[i])) ind=i;
            //     ans=min(ans,max(0ll,x-v[i])+max(0ll,y-sum+v[i]));
            //     cout<<max(0ll,x-v[i])+max(0ll,y-sum+v[i])<<' ';
            // }
            // cout<<ans<<' '<<ind<<'\n';
            int id=it-v.begin();
            auto it2=lower_bound(v.begin(),v.end(),x);
            int tt=n-1;
            if(it2!=v.begin()) 
            {
                it2--;
                tt=it2-v.begin();
            }
            // // cout<<id<< ' ';
            cout<<min({max(0ll,x-v[id])+max(0ll,y-sum+v[id]),max(0ll,x-v[0])+max(0ll,y-sum+v[0]),max(0ll,x-v[tt])+max(0ll,y-sum+v[tt])})<<'\n';
            // cout<<min(x-)
        }
        // int l=0,r=n-1,ans=INT_MAX;
        // while(l<=r)
        // {
        //     int mid=(l+r)/2;
        //     int temp=max(0ll,x-v[mid])+max(0ll,y-sum+v[mid]);
        //     if(temp<ans)
        //     {

        //     }
        // }
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