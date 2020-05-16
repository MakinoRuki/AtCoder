#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define N 5002
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
string s;
ll dp[N][N];
ll getpw(ll a, ll b) {
  ll res =1LL;
  while(b) {
    if (b&1) res = res*a % mod;
    a = a*a % mod;
    b /= 2;
  }
  return res;
}
int main() {
  cin>>n>>s;
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1LL;
  int m = s.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      dp[i+1][j+1] = (dp[i+1][j+1] + 2LL*dp[i][j]) % mod;
      if (j) {
        dp[i+1][j-1] = (dp[i+1][j-1] + dp[i][j]) % mod;
      } else {
        dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % mod;
      }
    }
  }
  ll ans = dp[n][m];
  //cout<<"ans="<<ans<<endl;
  ll res = getpw(2LL, m) % mod;
  res = getpw(res, mod-2) % mod;
  ans = ans*res%mod;
  cout<<ans<<endl;
  return 0;
}
