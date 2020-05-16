#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#define N 42
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, x, y, z;
int st[1<<16][11];
ll dp[N][1<<16];
bool check(vector<int>ds, int d) {
  reverse(ds.begin(), ds.end());
  ds.push_back(d);
  reverse(ds.begin(), ds.end());
  int sum=0;
  int i =0;
  while(i < ds.size()) {
    sum += ds[i];
    i++;
    if (sum >= z) break;
  }
  if (sum != z) return true;
  sum = 0;
  while(i < ds.size())  {
    sum += ds[i];
    i++;
    if (sum >= y) break;
  }
  if (sum != y) return true;
  sum = 0;
  while(i < ds.size()) {
    sum += ds[i];
    i++;
    if (sum >= x) break;
  }
  return sum != x;
}
int main() {
  cin>>n>>x>>y>>z;
  memset(st, -1, sizeof(st));
  for (int i = 0; i < (1<<16); ++i) {
    vector<int> ds;
    ds.clear();
    int j = i;
    while(j) {
      int cnt=0;
      while(!((1<<cnt)&j)) {
        cnt++;
      }
      ds.push_back(cnt+1);
      j >>= (cnt+1);
    }
    for (int j = 1; j <= 10; ++j) {
      if (check(ds, j)) {
       // if (i==0 && j==1) cout<<"ok!"<<endl;
        int sum=j;
        int k=0;
        int s2 = 1<<(j-1);
        int bits = j;
        for (; k < ds.size(); ++k) {
          if (sum + ds[k] > 16) break;
          sum += ds[k];
          bits += ds[k];
          s2 += 1<<(bits-1);
        }
      //  if (i==0 && j == 1) cout<<"s2="<<s2<<endl;
        st[i][j] = s2;
      }
    }
  }
  memset(dp, 0LL, sizeof(dp));
  dp[0][0] = 1LL;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < (1<<16); ++j) {
      if (!dp[i][j]) continue;
      for (int k = 1; k <= 10; ++k) {
        if (st[j][k] >= 0) {
          dp[i+1][st[j][k]] = (dp[i+1][st[j][k]] + dp[i][j]) % mod;
        }
      }
    }
  }
  ll ans=1LL;
  for (int i = 1; i <= n; ++i) {
    ans = ans * 10LL % mod;
  }
  for (int i = 0; i < (1<<16); ++i) {
    ans = (ans - dp[n][i]+mod) % mod;
  }
  cout<<ans<<endl;
  return 0;
}
