#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N, K;
vector<ll> C;
string A;
ll best;

void dfs(int d, int disp, int sold, ll revenue) {
    if (d == K) {
        best = max(best, revenue);
        return;
    }
    int rem = ((1<<N) - 1) & ~(disp | sold);
    // try all subsets of rem to add
    for (int add = 0; add < (1<<N); add++) {
        if ((add & rem) != add) continue;
        int new_disp = disp | add;
        int live = new_disp & ~sold;
        if (__builtin_popcount(live) < 2) continue;
        int pick;
        if (A[d] == '0') {
            pick = __builtin_ctz(live);
        } else {
            pick = 31 - __builtin_clz(live);
        }
        dfs(d+1, new_disp, sold | (1<<pick), revenue + C[pick]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    const ll MOD = 1000000007;
    while (T--){
        cin >> N >> K;
        C.resize(N);
        for (int i = 0; i < N; i++) cin >> C[i];
        cin >> A;
        best = 0;
        dfs(0, 0, 0, 0);
        cout << (best % MOD) << "\n";
    }
    return 0;
}
