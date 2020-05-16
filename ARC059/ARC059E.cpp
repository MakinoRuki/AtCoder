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
#define N 402
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, c;
int a[N], b[N];
ll cnt[N][N];
ll dp[N][N];
int main() {
  cin>>n>>c;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
  }
  memset(cnt, 0, sizeof(cnt));
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i <= c; ++i) {
    for (int j = 1; j <= 400; ++j) {
      ll pw = 1LL;
      for (int k = 1; k <= i; ++k) {
        pw = pw * (ll)j % mod;
      }
      cnt[i][j] = (cnt[i][j-1] + pw) % mod;
    }
  }
  for (int i = 0; i <= c; ++i) {
    dp[1][i] = (cnt[i][b[1]]-cnt[i][a[1]-1]+mod)%mod;
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j <= c; ++j) {
      for (int k = 0; j + k <= c; ++k) {
        dp[i+1][j+k] = (dp[i+1][j+k] + dp[i][j]*((cnt[k][b[i+1]]-cnt[k][a[i+1]-1]+mod)%mod)%mod) % mod;
      }
    }
  }
  cout<<dp[n][c]<<endl;
  return 0;
}
