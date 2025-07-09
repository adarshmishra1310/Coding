#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;
const ll NEG_INF = -4e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int N,K;
        cin >> N >> K;
        vector<ll> C(N+1);
        for(int i=1;i<=N;i++) cin >> C[i];
        string A;
        cin >> A;

        int z = 0, p = 0;
        for(char c: A){
            if(c=='0') z++;
            else p++;
        }

        // front[m]: sum of top‐z costs in C[1..m-1]
        vector<ll> front(N+2, NEG_INF);
        if(z==0){
            // if no zeros, front = 0 everywhere
            for(int m=1;m<=N;m++) front[m] = 0;
        } else {
            priority_queue<ll,vector<ll>,greater<ll>> pq;
            ll sum = 0;
            // we build prefix 1..i
            for(int i=1;i<=N;i++){
                // consider C[i] entering window [1..i]
                pq.push(C[i]);
                sum += C[i];
                if((int)pq.size() > z){
                    sum -= pq.top();
                    pq.pop();
                }
                // front for dummy at m = i+1 uses prefix 1..i
                if((int)pq.size() == z)
                    front[i+1] = sum;
                // else remains NEG_INF
            }
        }

        // back[m]: sum of top‐p costs in C[m+1..N]
        vector<ll> back(N+2, NEG_INF);
        if(p==0){
            for(int m=1;m<=N;m++) back[m] = 0;
        } else {
            priority_queue<ll,vector<ll>,greater<ll>> pq;
            ll sum = 0;
            // build suffix i..N
            for(int i=N;i>=1;i--){
                pq.push(C[i]);
                sum += C[i];
                if((int)pq.size() > p){
                    sum -= pq.top();
                    pq.pop();
                }
                // back for dummy at m = i-1 uses suffix i..N
                if((int)pq.size() == p)
                    back[i-1] = sum;
            }
        }

        // now try all m=1..N
        ll ans = 0;
        for(int m=1;m<=N;m++){
            if(front[m] > NEG_INF && back[m] > NEG_INF){
                ans = max(ans, front[m] + back[m]);
            }
        }

        cout << (ans % MOD) << "\n";
    }

    return 0;
}
