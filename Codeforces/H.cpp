#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,Q;
    cin>>N>>Q;
    vector<int> pc(N+1,0);
    int server = 0;
    vector<int> parent;
    vector<string> seg;
    parent.reserve(Q+1);
    seg.reserve(Q+1);
    parent.push_back(0);
    seg.push_back("");
    for(int i=0;i<Q;i++){
        int t,p;
        cin>>t>>p;
        if(t==1){
            pc[p]=server;
        } else if(t==2){
            string s;
            cin>>s;
            parent.push_back(pc[p]);
            seg.push_back(s);
            pc[p]=parent.size()-1;
        } else {
            server=pc[p];
        }
    }
    string ans;
    int cur=server;
    vector<string> parts;
    while(cur!=0){
        parts.push_back(seg[cur]);
        cur=parent[cur];
    }
    for(int i=parts.size()-1;i>=0;--i) ans+=parts[i];
    cout<<ans<<"\n";
    return 0;
}
