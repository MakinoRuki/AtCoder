#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#define N 200005
using namespace std;
int n, k, l;
int par1[N], par2[N];
map<pair<int, int>, int> cnt;
int find(int u, int* par) {
  return u == par[u] ? u : par[u] = find(par[u], par);
}
int main() {
  cin>>n>>k>>l;
  for (int i = 1; i <= n; ++i) {
    par1[i] = i;
    par2[i] = i;
  }
  cnt.clear();
  for (int i = 0; i < k; ++i) {
    int p, q;
    cin>>p>>q;
    int px = find(p, par1);
    int py = find(q, par1);
    if (px != py) {
      par1[px] = py;
    }
  }
  for (int i= 0; i < l; ++i) {
    int r, s;
    cin>>r>>s;
    int pr = find(r, par2);
    int ps = find(s, par2);
    if (pr != ps) {
      par2[pr] = ps;
    }
  }
  for (int i = 1; i <= n; ++i) {
    cnt[make_pair(find(i, par1), find(i, par2))]++;
  }
  for (int i = 1; i <= n; ++i) {
    cout<<cnt[make_pair(find(i, par1), find(i, par2))];
    if (i < n) cout<<" ";
    else cout<<endl;
  }
	return 0;
}
