
#include <bits/stdc++.h>
using namespace std;

const int inf = (int)1e18;
const int mod = 1e9 + 7;

// logic -> every length n can be broken in powers of two. hence precompute the minimum value
//          for every power of 2. this can be calculated using dp.
//          ex-> answer for length 4 = calc(length 2 , length 2)
//          while quering instead of breaking n in powers of two(7->4,2,1), we can just
//          break segment in two biggest powers of two, e.g. 7 -> 4,4.
//          because we don't care about overlapping in min or max(we do care in sum)
//          output the answer -> min(len k from l , len k from r-(1<<len)+1;
// Time complexity -> precomputation = O(n*log(n)), query = O(1)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    for(auto &x:v) cin>>x;

    // calculate log2 value for each value from 1 to n 
    vector<int> logg(n+1,0);
    for(int i=1;i<=n;i++)
    {
        int num=i;
        while(num>1)
        {
            num/=2;
            logg[i]++;
        }
    }

    // initialize sparse table
    vector<vector<int>> sp(n,vector<int>(logg[n]+1));
    for(int i=0;i<n;i++) sp[i][0]=v[i];
    for(int i=1;i<=logg[n];i++)
    {
        for(int j=0;j+(1<<i)<=n;j++)
        {
            sp[j][i]=min(sp[j][i-1],sp[j+(1<<(i-1))][i-1]);
        }
    }

    while(q--)
    {
        int l,r;
        cin>>l>>r;
        l--;r--;
        int k=logg[r-l+1];
        cout<<min(sp[l][k],sp[r-(1<<k)+1][k])<<'\n';
    }
    return 0;
}

// template <typename T>
// struct sparse {
//     int n;
//     int k;
//     vector<vector<T>> sp;

//     int logg(int n) { return n ? __builtin_clz(1) - __builtin_clz(n) : -1; }

//     T argmin(T a, T b) { return min(a, b); }

//     void precalc() {
//         for (int j = 1; j <= k; j++) {
//             for (int i = 0; i <= n - (1 << j); i++) {
//                 sp[i][j] = argmin(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
//             }
//         }
//     }

//     void init(vector<T> a) {
//         n = a.size();
//         k = logg(n);
//         sp.resize(n, vector<T>(k + 1));
//         for (int i = 0; i < n; i++) {
//             sp[i][0] = a[i];
//         }
//         precalc();
//     }

//     T calc(int l, int r) {
//         int p = logg(r - l);
//         return argmin(sp[l][p], sp[r - (1 << p)][p]);
//     }
// };