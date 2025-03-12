#include <bits/stdc++.h>
using namespace std;
#define int long long

const int inf = (int)1e18;
// const int mod = 1e9 + 7;

bool solve(int x, int y, int a, int rr)
{
    return ((x - a) * (x - a) + y * y) <= (rr * rr);
}

void runCase(int &testcase)
{
    int n, m;
    cin >> n >> m;
    vector<int> x(n), r(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < n; i++)
        cin >> r[i];
    vector<pair<int, int>> temp;
    for (int i = 0; i < n; i++)
        temp.push_back({x[i], r[i]});
    sort(temp.begin(), temp.end());
    multiset<pair<int,int>> ss;
    for (int i = 0; i < n; i++)
    {
        x[i] = temp[i].first;
        r[i] = temp[i].second;
    }
    vector<int> lf(2 * n + 1);
    int mx = n - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        lf[i] = mx;
        if ((x[i] - r[i]) < (x[mx] - r[mx]))
        {
            mx = i;
        }
        else if((x[i] - r[i]) <= (x[mx] - r[mx]))
        {
            if(r[i]>=r[mx])
            {
                mx=i;
            }
        }
    }
    int cnt = 0, flag = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = -1 * r[i]; j <= r[i]; j++)
        {
            int temp = (int)sqrt((r[i] * r[i]) - (j * j));
            for (int k = temp; k >= -1 * temp; k--)
            {
                if ((i < n - 1) && solve(x[i] + j, k, x[lf[i]], r[lf[i]]))
                {
                    continue;
                }
                // if((x[i]+j)==1 && k==2)
                // {
                //     // cout<<lf[i]<<' ';
                //     // cout<<i<<"H\n";
                // }
                // cout<<x[i]+j<<' '<<k<<'\n';
                // ss.insert({x[i]+j,k});
                cnt++;
            }
        }
    }
    // for(auto &x:ss) cout<<x.first<<' '<<x.second<<'\n';
    cout << cnt << '\n';
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