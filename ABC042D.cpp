#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 300005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll h,w,a,b;
ll comb1[N], comb2[N];
ll getpw(ll x) {
  ll res=1LL;
  ll b = mod-2;
  while(b) {
  	if (b&1) res = res*x%mod;
    x = x*x%mod;
    b /= 2;
  }
  return res;
}
void calc(ll* comb, int n) {
  comb[0]=1LL;
  ll up = 1LL;
  ll down = 1LL;
  for (int i = 1; i <= n; ++i) {
  	up = up * (ll)(n- (i-1)) % mod;
    down = down * (ll)i % mod;
    comb[i] = up * getpw(down) % mod;
  }
}
int main() {
  cin>>h>>w>>a>>b;
  memset(comb1, 0, sizeof(comb1));
  memset(comb2, 0, sizeof(comb2));
  calc(comb1, h-a+b-1);
  calc(comb2, a-b+w-1);
 // cout<<comb1[0]<<" "<<comb2[1]<<endl;
  ll ans=0LL;
  // 在前H-A+B-1步中向下的步数必须小于H-A。
  for (int i= 0; i < h-a; ++i) {
  	ans = (ans + comb1[i]*comb2[h-1-i]%mod)%mod;
  }
  cout<<ans<<endl;
  return 0;
}
