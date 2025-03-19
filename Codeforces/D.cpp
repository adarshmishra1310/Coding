#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSmooth(const vector<long long>& a) {
    if(a.size() <= 1) return true;
    for (int i = 0; i < a.size()-1; i++)
        if(a[i] >= a[i+1]) return false;
    vector<long long> d;
    for (int i = 0; i < a.size()-1; i++)
        d.push_back(a[i+1] - a[i]);
    return isSmooth(d);
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<long long> A(n);
        for(int i = 0; i < n; i++)
            cin >> A[i];
        string ans(n, '0');
        for(int i = 0; i < n; i++){
            vector<long long> B;
            for(int j = 0; j < n; j++){
                if(j == i) continue;
                B.push_back(A[j]);
            }
            ans[i] = isSmooth(B) ? '1' : '0';
        }
        cout << ans << "\n";
    }
    return 0;
}
