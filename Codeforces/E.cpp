#include <bits/stdc++.h>

#define int long long
using namespace std;

const int mod = 998244353;

void solve() {
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int start=0;
	int end=1e6;
	while(start!=end){
		int mid=(start+end+1)/2;
		int mex=0;
		set<int> s;
		int cnt=0;
		for(int i=0;i<n;i++){
			s.insert(a[i]);
			while(s.size()&&mex<mid){
				if(s.find(mex)!=s.end()){
					s.erase(mex);
					++mex;
				}
				else{
					break;
				}
			}
			if(mex==mid){
				cnt++;
				s.clear();
				mex=0;
			}
		}
		if(cnt>=k){
			start=mid;
		}
		else{
			end=mid-1;
		}
	}
	cout<<start<<"\n";
}

int32_t main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}