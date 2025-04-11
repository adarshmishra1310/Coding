#include <bits/stdc++.h>
using namespace std;
#define int long long

//const int inf = (int)1e18;
//const int mod = 1e9 + 7;

void runCase(int &testcase)
{
    int n,q;
    cin>>n>>q;
    while(q--)
    {
        char c,d;
        cin>>c>>d;
        if(c=='<')
        {
            int num;
            cin>>num;
            int tn=(1ll<<2*n),st=1;
            int l=1,r=1;
            while(true)
            {
                int cj=tn;
                int j=tn/4,cnt=0;
                int gl=0,g2=0;
                while(1)
                {
                    st+=j;
                    cnt++;
                    if(st>num)
                    {
                        break;
                    }
                    if(cnt==1)
                    {
                        gl=l+tn/2;
                    }
                }
            }
        }
        else
        {
            int x,y;
            cin>>x>>y;
        }
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