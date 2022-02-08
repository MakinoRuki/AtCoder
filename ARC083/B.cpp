// 利用已有信息求(u,v)最短路。
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
#define M 500005
#define N 302
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N][N];
ll mat[N][N];
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      mat[i][j] = (i == j ? 0 : (1LL<<61)-1);
    }
  }
  vector<pair<int, pair<int,int>>> rk;
  rk.clear();
  for (int i = 1; i <= n; ++i) {
    for (int j = i+1; j <= n; ++j) {
      rk.push_back(make_pair(a[i][j], make_pair(i, j)));
    }
  }
  sort(rk.begin(), rk.end());
  ll tot=0LL;
  for (int i = 0; i < rk.size(); ++i) {
    ll w = rk[i].first;
    int u = rk[i].second.first;
    int v = rk[i].second.second;
    int j;
    for (j = 1; j <= n; ++j) {
      if (j != u && j != v && a[u][j]+a[j][v] == w) {
        break;
      }
    }
    if (j <= n) continue;
    mat[u][v] = mat[v][u] = w;
    tot += w;
  }
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (mat[i][k] < (1LL<<61)-1 && mat[k][j] < (1LL<<61)-1 && mat[i][k]+mat[k][j] < mat[i][j]) {
          mat[i][j] = mat[i][k]+mat[k][j];
        }
      }
    }
  }
  bool ok=true;
  for (int i =1;i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (mat[i][j] != a[i][j]) {
        ok=false;
        break;
      }
    }
    if (!ok) break;
  }
  if (ok) cout<<tot<<endl;
  else puts("-1");
  return 0;
}

