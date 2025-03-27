#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
#define no cout << "NO\n"

void solve()
{
  int n;
  cin >> n;
  string str;
  cin >> str;
  int ans = 1;
  for (int i = 0; i <= (n-1)/2; i++)
  {
    if (str[i] == str[n-i-1])
      ans = 0;
  }
  if (ans)
  {
    cout << 0 << endl;
    return;
  }
  if(n % 2 !=0) {
    cout<<"-1"<<endl;
    return;
  }
  ans=1;
  

  string s(2000, 4);

  int count = 0 , l= 1000 , r=1000+n-1; // l=0,r=n-1;

  for(int i=0;i<n;i++){
    s[i+1000]=str[i];
  }

  int rl=1000,rr=r;
  vector<int>res;
  while (count <= 300 && l<=r){
    if (s[l]=='0' && s[r]=='1') {
      l++,r--;
    }
    else if (s[l]=='1' && s[r]=='0'){
      l++,r--;
    }
    else if(s[l]=='0' && s[r]=='0'){
      l++;
      r++;
      s[r]='0';
      s[r+1]='1';
      res.push_back(r-rl);
      rr+=2;
      count++;
    }
    else if (s[l]=='1' && s[r]=='1'){
          res.push_back(l-rl);
      r--;
      l--;
      s[l]='1';
      s[l-1]='0';
      rl-=2;
      count++;
    }
  }
  if(count <=300){
    cout<<count <<endl;
    for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
    cout<<endl;
  }else cout<<"-1"<<endl;
  return;
}

int main()
{
  ll t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}
